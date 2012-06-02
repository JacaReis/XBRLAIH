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

#include "Headers/LeitorBackup.h"

#include "Headers/Aih.h"

#include <QFile>
#include <QFileInfo>
#include <QTextStream>

LeitorBackup::LeitorBackup( QString caminhoBackup, QObject *parent )
    : QObject( parent )
    , m_arquivoBackup( new QFile( caminhoBackup ) )
{
}

LeitorBackup::~LeitorBackup()
{
    m_arquivoBackup->close();
    m_aihs.clear();

    delete m_arquivoBackup;
    delete m_textStream;
}

bool LeitorBackup::abrirBackup()
{
    if ( !m_arquivoBackup->open( QIODevice::ReadOnly | QIODevice::Text ) )
        return false;

    m_textStream = new QTextStream( m_arquivoBackup );
    return true;
}

void LeitorBackup::lerAihs()
{
    Aih *aih;

    while ( !m_arquivoBackup->atEnd() )
    {
        aih = new Aih();
        inicializarAih( aih );

        if ( aih )
        {
            m_aihs.append( aih );
        }
    }

    emit aihsCarregadas();
}

void LeitorBackup::inicializarAih( Aih* aih )
{

    if ( m_textStream->read( 95 ).length() != 95 )
    {
        delete aih;
        return;
    }
    else
        m_textStream->seek( m_textStream->pos() - 95 );

    //Parte comum para todos os registros de AIH
    aih->setNumeroLote( m_textStream->read( 8 ) );
    aih->setQuantidadeLote( m_textStream->read( 3 ) );
    aih->setApresentacaoLote( m_textStream->read( 6 ) );
    aih->setSequencialLote( m_textStream->read( 3 ) );
    aih->setOrgaoEmissor( m_textStream->read( 10 ) );
    aih->setCnesHospital( m_textStream->read( 7 ) );
    aih->setMunicipioHospital( m_textStream->read( 6 ) );
    aih->setNumeroAih( m_textStream->read( 13 ) );
    aih->setIdentificacaoAih( m_textStream->read( 2 ) );
    aih->setEspecialidadeAih( m_textStream->read( 2 ) );
    m_textStream->read( 45 ); //Filler

    switch( aih->identificacaoAih().toInt() )
    {
    case 1: //AIH principal
    case 3: //AIH de continuacao
    case 5: //AIH de longa permanencia
        {
            aih->setModalidadeAih( m_textStream->read( 2 ) );
            aih->setSequencialAih( m_textStream->read( 3 ) );
            aih->setNumeroProximaAih( m_textStream->read( 13 ) );
            aih->setNumeroAnteriorAih( m_textStream->read( 13 ) );
            aih->setDataEmissaoAih( m_textStream->read( 8 ) );
            aih->setDataInternacao( m_textStream->read( 8 ) );
            aih->setDataSaida( m_textStream->read( 8 ) );
            aih->setProcedimentoSolicitado( m_textStream->read( 10 ) );
            aih->setMudancaProcedimento( m_textStream->read( 1 ) );
            aih->setProcedimentoRealizado( m_textStream->read( 10 ) );
            aih->setCaraterInternacao( m_textStream->read( 2 ) );
            aih->setMotivoSaidaPermanencia( m_textStream->read( 2 ) );
            aih->setIdentificadorMedicoSolicitante( m_textStream->read( 1 ) );
            aih->setDocumentoMedicoSolicitante( m_textStream->read( 15 ) );
            aih->setIdentificadorMedicoResponsavel( m_textStream->read( 1 ) );
            aih->setDocumentoMedicoResponsavel( m_textStream->read( 15 ) );
            aih->setIdentificadorDiretorClinico( m_textStream->read( 1 ) );
            aih->setDocumentoDiretorClinico( m_textStream->read( 15 ) );
            aih->setIdentificadorMedicoAutorizador( m_textStream->read( 1 ) );
            aih->setDocumentoMedicoAutorizador( m_textStream->read( 15 ) );
            aih->setDiagnosticoPrincipal( m_textStream->read( 4 ) );
            aih->setDiagnosticoSecundario( m_textStream->read( 4 ) );
            aih->setDiagnosticoCausasComplementares( m_textStream->read( 4 ) );
            aih->setDiagnosticoCausaMorte( m_textStream->read( 4 ) );
            aih->setCodigoSolicitacaoLiberacao( m_textStream->read( 3 ) );

            //Paciente
            aih->setNomePaciente( m_textStream->read( 70 ) );
            aih->setDataNascimentoPaciente( m_textStream->read( 8 ) );
            aih->setSexoPaciente( m_textStream->read( 1 ) );
            aih->setRacaPaciente( m_textStream->read( 2 ) );
            aih->setNomeMaePaciente( m_textStream->read( 70 ) );
            aih->setNomeResponsavelPaciente( m_textStream->read( 70 ) );
            aih->setTipoDocumentoPaciente( m_textStream->read( 1 ) );
            aih->setEtniaIndigena( m_textStream->read( 4 ) );
            m_textStream->read( 7 ); //Filler

            aih->setNumeroCartaoSaudePaciente( m_textStream->read( 15 ) );
            aih->setNacionalidadePaciente( m_textStream->read( 3 ) );

            //Endereco do paciente
            aih->setCodigoTipoLogradouroPaciente( m_textStream->read( 3 ) );
            aih->setLogradouroPaciente( m_textStream->read( 50 ) );
            aih->setNumeroLogradouroPaciente( m_textStream->read( 7 ) );
            aih->setComplementoEnderecoPaciente( m_textStream->read( 15 ) );
            aih->setBairro( m_textStream->read( 30 ) );
            aih->setMunicipioEnderecoPaciente( m_textStream->read( 6 ) );
            aih->setUfEnderecoPaciente( m_textStream->read( 2 ) );
            aih->setCepEnderecoPaciente( m_textStream->read( 8 ) );
            aih->setNumeroProntuario( m_textStream->read( 15 ) );
            aih->setNumeroEnfermaria( m_textStream->read( 4 ) );
            aih->setNumeroLeito( m_textStream->read( 4 ) );

            //Procedimentos secundarios/especiais
            for ( int i = 0; i < 10; ++i )
            {
                aih->aihProcedimentosSecundarios( i )->setIndicadorDocumentoProfissional( m_textStream->read( 1 ) );
                aih->aihProcedimentosSecundarios( i )->setIdentificacaoProfissional( m_textStream->read( 15 ) );
                aih->aihProcedimentosSecundarios( i )->setCodigoCBO( m_textStream->read( 6 ) );
                aih->aihProcedimentosSecundarios( i )->setIndicadorEquipe( m_textStream->read( 1 ) );
                aih->aihProcedimentosSecundarios( i )->setIndicadorPrestadorServico( m_textStream->read( 1 ) );
                aih->aihProcedimentosSecundarios( i )->setIdentificacaoPrestadorServico( m_textStream->read( 14 ) );
                aih->aihProcedimentosSecundarios( i )->setIndicadorDocumentoExecutor( m_textStream->read( 1 ) );
                aih->aihProcedimentosSecundarios( i )->setIndentificacaoExecutor( m_textStream->read( 15 ) );
                aih->aihProcedimentosSecundarios( i )->setCodigoProcedimento( m_textStream->read( 10 ) );
                aih->aihProcedimentosSecundarios( i )->setQuantidadeProcedimentos( m_textStream->read( 3 ) );
                aih->aihProcedimentosSecundarios( i )->setCompetencia( m_textStream->read( 6 ) );
            }

            //UTI Neonatal
            aih->setSaidaUtiNeoNatal( m_textStream->read( 1 ) );
            aih->setPesoAoNascer( m_textStream->read( 4 ) );
            aih->setNumeroMesesGestacao( m_textStream->read( 1 ) );

            //Acidente de Trabalho
            aih->setCnpjEmpregador( m_textStream->read( 14 ) );
            aih->setCodigoCBOR( m_textStream->read( 6 ) );
            aih->setCodigoCNAER( m_textStream->read( 3 ) );
            aih->setTipoVinculoPrevidencia( m_textStream->read( 1 ) );

            //Em caso de parto
            aih->setQuantidadeNascidosVivos( m_textStream->read( 1 ) );
            aih->setQuantidadeNascidosMortos( m_textStream->read( 1 ) );
            aih->setQuantidadeSaidasPorAlta( m_textStream->read( 1 ) );
            aih->setQuantidadeSaidasPorTransferencia( m_textStream->read( 1 ) );
            aih->setQuantidadeSaidasPorObito( m_textStream->read( 1 ) );
            m_textStream->read( 10 ); //Filler

            //aih->setNumeroInscricaoGestantePreNatal( m_textStream->read( 11 ) );

            //Em caso de Laqueadura ou vasectomia
            aih->setNumeroFilhos( m_textStream->read( 2 ) );
            aih->setGrauInstrucao( m_textStream->read( 1 ) );
            aih->setCidNotificacaoIndicacao( m_textStream->read( 4 ) );
            aih->setTipoMetodoContraceptivo( m_textStream->read( 2 ) );
            aih->setTipoMetodoContraceptivo2( m_textStream->read( 2 ) );
            aih->setGestacaoAltoRisco( m_textStream->read( 1 ) );

            m_textStream->read( 35 ); //Reservado
            aih->setNumeroInscricaoGestantePreNatal( m_textStream->read( 11 ) );
            aih->setNumeroDocumentoPaciente( m_textStream->read( 32 ) );
            m_textStream->read( 73 ); //Filler
            break;
        }
    case 4: //AIH de registro civil
        {
            m_textStream->read( 1496 );
            delete aih;
            break;
        }
    case 7: //Dados da OPM
        {
            m_textStream->read( 1496 );
            delete aih;
            break;
        }
    default:
        {
            emit erro( QString( "Erro.: O código de identificacao de AIH de numero %1 é inválido." ).arg( aih->identificacaoAih() ) );
            delete aih;
        }
    }
}
