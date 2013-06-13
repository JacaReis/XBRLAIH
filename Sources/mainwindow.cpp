/****************************************************************************************
 * Copyright (c) 2012 Lucas Lira Gomes <x8lucas8x@gmail.com>                            *
 * Copyright (c) 2012 Raony Benjamim <raonybenjamim@gmail.com>                          *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"

#include "Headers/GeradorEstatistica.h"
#include "Headers/InstanciadorXbrl.h"
#include "Headers/LeitorBackup.h"
#include "Headers/LeitorCompetencia.h"

#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include <QProgressDialog>
#include <QTextStream>
#include <QtXml>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlSerializer>
#include <QXmlQuery>
#include <QDebug>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
    , m_leitorBackup( NULL )
    , m_leitorCompetencia( NULL )
    , m_instanciadorXbrl( NULL )
    , m_geradorEstatistica( NULL )
    , m_progressDialog( NULL )
{
    ui->setupUi( this );

    ui->voltarPushButton->setVisible( false );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_abrirBackupPushButton_clicked()
{
    QString localizacaoBackup =
            QFileDialog::getOpenFileName( this,
                                          tr( "Selecione o arquivo de exportação" ),
                                          qApp->applicationDirPath(),
                                          tr( "Arquivo de exportação do SISAIH (*.txt)" ) );

    if ( !localizacaoBackup.isEmpty() )
        ui->backupLineEdit->setText( localizacaoBackup );

    if ( ehPossivelGerarInstanciaXBRL() )
        ui->gerarRelatorioPushButton->setEnabled( true );
}

void MainWindow::on_abrirCompetenciaPushButton_clicked()
{
    QString localizacaoDiretorio =
            QFileDialog::getExistingDirectory( this,
                                               tr( "Selecione o diretório da competência" ),
                                               qApp->applicationDirPath() );

    if ( !localizacaoDiretorio.isEmpty() )
        ui->competenciaLineEdit->setText( localizacaoDiretorio );

    if ( ehPossivelGerarInstanciaXBRL() )
        ui->gerarRelatorioPushButton->setEnabled( true );
}

void MainWindow::on_gerarRelatorioPushButton_clicked()
{
    ui->saidaTextEdit->clear();

    if( extrairResource( QUrl( "taxonomia/hc_20111007.xsd" ), ":/taxonomia/taxonomia" ) &&
        extrairResource( QUrl( "taxonomia/hc_cal20111007.xml" ), ":/taxonomia/calculationLinkBase" ) &&
        extrairResource( QUrl( "taxonomia/hc_def20111007.xml" ), ":/taxonomia/definitionLinkBase" ) &&
        extrairResource( QUrl( "taxonomia/hc_lab20111007.xml" ), ":/taxonomia/labelLinkBase" ) &&
        extrairResource( QUrl( "taxonomia/hc_pre20111007.xml" ), ":/taxonomia/presentationLinkBase" ) &&
        extrairResource( QUrl( "taxonomia/hc_ref20111007.xml" ), ":/taxonomia/referenceLinkBase" ) &&
        extrairResource( QUrl( "html.xq" ), ":/folhaDeEstilo/html" )
      )
    {
        ui->saidaTextEdit->append( tr( "--- Arquivos dos resources extraídos com sucesso" ) );

        if ( m_progressDialog )
            delete m_progressDialog;

        m_progressDialog = new QProgressDialog( tr( "Gerando o relatório da prévia..." ),
                                                tr( "Cancelar" ),
                                                0 ,
                                                8,
                                                this );

        m_progressDialog->setLabelText( tr( "Inicializando os leitores..." ) );
        m_progressDialog->setValue( 1 );
        m_progressDialog->setAutoClose( true );

        if ( inicializarLeitorBackup() && inicializarLeitorCompetencia() )
        {
            if ( m_geradorEstatistica )
                delete m_geradorEstatistica;

            m_geradorEstatistica =
                    new GeradorEstatistica( m_leitorBackup->aihs(),
                                            m_leitorCompetencia->procedimentos(),
                                            this );
            int ano_c = m_geradorEstatistica->anoCompetencia();
            int mes_c = m_geradorEstatistica->mesCompetencia();
            int ano_l = m_geradorEstatistica->anoApresentacaoLote();
            int mes_l = m_geradorEstatistica->mesApresentacaolote();

            /*if(ano_c == ano_l && mes_c == mes_l){
                qDebug() << "passou ";
                qDebug() << ano_c;
                qDebug() << ano_l;
                qDebug() << mes_c;
                qDebug() << mes_l;
            }else{
                qDebug() << "nao passou ";
                qDebug() << ano_c;
                qDebug() << ano_l;
                qDebug() << mes_c;
                qDebug() << mes_l;
            }*/

            if( m_geradorEstatistica->datasConferem() )
            {

                QString localizacaoInstancia = "instancia.xml";

                if ( m_instanciadorXbrl )
                    delete m_instanciadorXbrl;

                m_instanciadorXbrl =
                        new InstanciadorXbrl( localizacaoInstancia,
                                              m_geradorEstatistica,
                                              QUrl( qApp->applicationFilePath() )
                                              .resolved( QUrl( "taxonomia/hc_20111007.xsd" ) ).toLocalFile(),
                                              this );

                connect( m_instanciadorXbrl, SIGNAL(xbrlPreenchido(QString)),
                         this, SLOT(xbrlPreenchido()) );

                if ( m_instanciadorXbrl->criarXml() )
                {

                    ui->saidaTextEdit->append( tr( "--- Instância XBRL criada" ) );
                    m_progressDialog->setLabelText( tr( "Instância XBRL criada..." ) );
                    m_progressDialog->setValue( 6 );
                    m_instanciadorXbrl->preencherXbrl();


                }
                else
                {
                    ui->saidaTextEdit->append( tr( "Erro.: Não foi possível criar a instância XBRl" ) );
                }
            }
            else
            {
                QMessageBox::critical( this,
                                       tr( "Erro" ),
                                       tr( "Você precisa escolher uma competência compatível com a\n"
                                           "data de apresentaćão do lote do arquivo de exportação ." ),
                                       QMessageBox::Ok );

                ui->saidaTextEdit->append( tr( "Erro.: Você precisa escolher uma competência compatível com a"
                                               "data de apresentaćão do lote do arquivo de exportação." ) );

            }
        }
    }
    else
        ui->saidaTextEdit->append( tr( "Erro.: Não foi possível extrair os resources necessários" ) );
}

bool MainWindow::ehPossivelGerarInstanciaXBRL()
{
    return ( ( !ui->backupLineEdit->text().isEmpty() ) &&
             ( !ui->competenciaLineEdit->text().isEmpty() ) );
}

bool MainWindow::inicializarLeitorBackup()
{
    if ( m_leitorBackup )
        delete m_leitorBackup;

    m_leitorBackup = new LeitorBackup( ui->backupLineEdit->text(), this );

    connect( m_leitorBackup, SIGNAL(erro(QString)), this, SLOT(mostrarErro(QString)) );
    connect( m_leitorBackup, SIGNAL(aihsCarregadas()), this, SLOT(aihsCarregadas()) );

    ui->saidaTextEdit->append( tr( "--- Carregando as AIHs do arquivo de exportação..." ) );
    m_progressDialog->setLabelText( tr( "Inicializando o leitor do arquivo de exportação..." ) );
    m_progressDialog->setValue( 2 );

    if ( !m_leitorBackup->abrirBackup() )
    {
        ui->saidaTextEdit->append( tr( "Erro.: Não foi possível abrir o arquivo de exportação" ) );
    }
    else
    {
        ui->saidaTextEdit->append( tr( "--- O arquivo de exportação foi aberto" ) );
        m_progressDialog->setLabelText( tr( "Lendo o arquivo de exportação aberto..." ) );
        m_progressDialog->setValue( 3 );
        m_leitorBackup->lerAihs();

        return true;
    }

    return false;
}

bool MainWindow::inicializarLeitorCompetencia()
{
    if ( m_leitorCompetencia )
        delete m_leitorCompetencia;

    m_leitorCompetencia = new LeitorCompetencia( ui->competenciaLineEdit->text(), this );

    connect( m_leitorCompetencia, SIGNAL(competenciaCarregada()),
             this, SLOT(competenciaCarregada()) );

    ui->saidaTextEdit->append( tr( "--- Carregando os procedimentos da competência escolhida..." ) );
    m_progressDialog->setLabelText( tr( "Inicializando o leitor da competência..." ) );
    m_progressDialog->setValue( 4 );

    if ( !m_leitorCompetencia->abrirCompetencia() )
    {
        ui->saidaTextEdit->append( tr( "Erro.: Não foi possível abrir os arquivos da competência escolhida" ) );
    }
    else
    {
        ui->saidaTextEdit->append( tr( "--- Os arquivos da competência foram abertos" ) );
        m_progressDialog->setLabelText( tr( "Lendo os arquivos da competência abertos..." ) );
        m_progressDialog->setValue( 5 );
        m_leitorCompetencia->inicializarCompetencia();

        return true;
    }

    return false;
}

void MainWindow::mostrarErro( const QString &mensagem )
{
    ui->saidaTextEdit->append( mensagem );
}

void MainWindow::aihsCarregadas()
{
    ui->saidaTextEdit->append( tr( "---Arquivo de exportação carregado com sucesso" ) );
    m_progressDialog->setLabelText( tr( "O arquivo de exportação foi carregado..." ) );
}

void MainWindow::competenciaCarregada()
{
    ui->saidaTextEdit->append( tr( "--- Competência carregada com sucesso" ) );
    m_progressDialog->setLabelText( tr( "A competência foi carregada..." ) );
}

void MainWindow::xbrlPreenchido()
{
    ui->saidaTextEdit->append( tr( "--- Instância XBRL preenchida com sucesso" ) );
    m_progressDialog->setLabelText( tr( "Instância XBRL preenchida..." ) );
    m_progressDialog->setValue( 7 );

    QString localizacaoSaida = "relatorio";

    if ( aplicarFolhaEstilo( QString( "%1.html" ).arg( localizacaoSaida ), "html.xq" ) )
    {

        ui->continuarPushButton->setEnabled( true );
        ui->gerarRelatorioPushButton->setEnabled( false );

        ui->webView->load( QUrl( QString( "%1.html" ).arg( localizacaoSaida ) ) );
        ui->webView->show();
        ui->saidaTextEdit->append( tr( "--- Folha de estilo HTML aplicada com sucesso..." ) );

        m_progressDialog->setLabelText( tr( "Folha de estilo HTML aplicada..." ) );
    }
    else
        ui->saidaTextEdit->append( tr( "Erro.: Falha na aplicação da folha de estilo HTML" ) );

    m_progressDialog->setValue( 8 );

    ui->saidaTextEdit->append( tr( "--- Fim da Execucao..." ) );
}

void MainWindow::slotDadosModificasdos()
{
    ui->gerarRelatorioPushButton->setEnabled( true );
}

// aplica a folha de estilo no Xbrl criado e também salva em pasta especifica
bool MainWindow::aplicarFolhaEstilo( const QString localizacaoArquivoSaida, const QString localizacaoArquivoXq )
{
    QFile xq( localizacaoArquivoXq );

    if( xq.exists() )
    {

        QString  name = QFileDialog::getSaveFileName(this);
        QFile saidaFormatada(name );
        QFile saidaFormatada2(localizacaoArquivoSaida);

        saidaFormatada.open( QIODevice::WriteOnly | QIODevice::Text );
        saidaFormatada2.open( QIODevice::WriteOnly | QIODevice::Text );

        if( saidaFormatada.isOpen() )
        {
            xq.open( QIODevice::ReadOnly | QIODevice::Text );

            if( xq.isOpen() )
            {
                QXmlQuery query;
                query.bindVariable( "inputDocument", QVariant( QUrl( "instancia.xml" ) ) );
                query.setQuery( &xq , QUrl::fromLocalFile( localizacaoArquivoXq ) );

                if( query.isValid() )
                {
                    QXmlSerializer serializer( query, &saidaFormatada );
                    query.evaluateTo( &serializer );

                    QXmlSerializer serializer2( query, &saidaFormatada2 );
                    query.evaluateTo( &serializer2 );

                    xq.close();
                    saidaFormatada.close();
                    saidaFormatada2.close();
                    return true;
                }

                xq.close();

            }

            saidaFormatada.close();
            saidaFormatada2.close();
        }
    }

    return false;
}

bool MainWindow::extrairResource( const QUrl localizacaoArquivo, const QString nomeRecurso )
{
    QFileInfo resource( localizacaoArquivo.path() );

    if( !resource.exists() )
    {
        QDir diretorio( resource.dir() );

        if( !diretorio.exists() )
            if( !diretorio.mkpath( diretorio.path() ) )
                return false;

        QFile arquivoResource( nomeRecurso );
        QFile arquivoSaida( resource.absoluteFilePath() );
        arquivoSaida.open( QIODevice::WriteOnly | QIODevice::Text );

        if( arquivoSaida.isOpen() )
        {
            arquivoResource.open( QIODevice::ReadOnly | QIODevice::Text );

            if( arquivoResource.isOpen() )
            {
                arquivoSaida.write( arquivoResource.readAll() );

                arquivoSaida.close();
                arquivoResource.close();

                return true;
            }

            arquivoSaida.close();
        }

        return false;
    }

    return true;
}

void MainWindow::on_verLogpushButton_clicked()
{
    if( ui->verLogpushButton->isChecked() )
        ui->modeStackWidget->setCurrentIndex( 1 );
    else
        ui->modeStackWidget->setCurrentIndex( 0 );
}

void MainWindow::on_voltarPushButton_clicked()
{
    switch( ui->mainStackWidget->currentIndex() )
    {
    case 0: break;
    case 1:
    {
        ui->voltarPushButton->setVisible( false );
    }
        break;
    case 2:
    case 3:
    case 4:
    {
        ui->continuarPushButton->setEnabled( true );
        ui->continuarPushButton->setVisible( true );
    }
        break;
    }

    ui->mainStackWidget->setCurrentIndex( ui->mainStackWidget->currentIndex() - 1 );
}

void MainWindow::on_continuarPushButton_clicked()
{
    switch( ui->mainStackWidget->currentIndex() )
    {
    case 0:
    {
        ui->voltarPushButton->setVisible( true );
    }
        break;
    case 1:
    {

        if( ui->backupLineEdit->text().isEmpty() )
        {
            QMessageBox::critical( this,
                                   tr( "Erro" ),
                                   tr( "Você precisa escolher um arquivo de exportação." ),
                                   QMessageBox::Ok );
            return;
        }
    }
        break;
    case 2:
    {
        if( ui->competenciaLineEdit->text().isEmpty() )
        {
            QMessageBox::critical( this,
                                   tr( "Erro" ),
                                   tr( "Você precisa escolher o diretório da competência." ),
                                   QMessageBox::Ok );
            return;
        }

        ui->continuarPushButton->setEnabled( !ui->gerarRelatorioPushButton->isEnabled() );

    }
        break;
    case 3:
    {
        ui->continuarPushButton->setVisible( false );
    }
        break;
    case 4: break;
    }

    ui->mainStackWidget->setCurrentIndex( ui->mainStackWidget->currentIndex() + 1 );
}

void MainWindow::on_abrirRelatorioPushButton_clicked()
{
    QDesktopServices::openUrl( ui->webView->url() );
}

void MainWindow::on_imprimirRelatorioPushButton_clicked()
{
    QPrinter printer;
    QPrintDialog printDlg( &printer );
    if ( printDlg.exec() == QDialog::Rejected )
        return;

    ui->webView->print( &printer );
}
