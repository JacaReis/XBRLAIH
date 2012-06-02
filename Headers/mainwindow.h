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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>

namespace Ui {
    class MainWindow;
}

class GeradorEstatistica;
class InstanciadorXbrl;
class LeitorBackup;
class LeitorCompetencia;
class LeitorFinanciamento;
class LeitorProcedimento;
class LeitorRubrica;

class QProgressDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0 );
    ~MainWindow();

private slots:
    void mostrarErro( const QString &mensagem );

    void aihsCarregadas();
    void competenciaCarregada();
    void xbrlPreenchido();
    void slotDadosModificasdos();

    void on_abrirBackupPushButton_clicked();
    void on_abrirCompetenciaPushButton_clicked();
    void on_gerarRelatorioPushButton_clicked();
    void on_verLogpushButton_clicked();
    void on_voltarPushButton_clicked();
    void on_continuarPushButton_clicked();
    void on_abrirRelatorioPushButton_clicked();
    void on_imprimirRelatorioPushButton_clicked();

private:
    Ui::MainWindow *ui;

    LeitorBackup *m_leitorBackup;
    LeitorCompetencia *m_leitorCompetencia;
    InstanciadorXbrl *m_instanciadorXbrl;
    GeradorEstatistica *m_geradorEstatistica;
    QProgressDialog *m_progressDialog;

    bool ehPossivelGerarInstanciaXBRL();

    bool aplicarFolhaEstilo( const QString localizacaoArquivoSaida, const QString localizacaoArquivoXq );

    bool extrairResource( const QUrl localizacaoArquivo, const QString nomeRecurso );

    bool inicializarLeitorBackup();
    bool inicializarLeitorCompetencia();
};

#endif // MAINWINDOW_H
