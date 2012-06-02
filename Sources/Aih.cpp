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

#include "Headers/Aih.h"

Aih::Aih()
    : m_numeroLote( "" )
    , m_quantidadeLote( "" )
    , m_apresentacaoLote( "" )
    , m_sequencialLote( "" )
    , m_orgaoEmissor( "" )
    , m_cnesHospital( "" )
    , m_municipioHospital( "" )
    , m_numeroAih( "" )
    , m_identificacaoAih( "" )
    , m_especialidadeAih( "" )
    , m_modalidadeAih( "" )
    , m_sequencialAih( "" )
    , m_numeroProximaAih( "" )
    , m_numeroAnteriorAih( "" )
    , m_dataEmissaoAih( "" )
    , m_dataInternacao( "" )
    , m_dataSaida( "" )
    , m_procedimentoSolicitado( "" )
    , m_mudancaProcedimento( "" )
    , m_procedimentoRealizado( "" )
    , m_caraterInternacao( "" )
    , m_motivoSaidaPermanencia( "" )
    , m_identificadorMedicoSolicitante( "" )
    , m_documentoMedicoSolicitante( "" )
    , m_identificadorMedicoResponsavel( "" )
    , m_documentoMedicoResponsavel( "" )
    , m_identificadorDiretorClinico( "" )
    , m_documentoDiretorClinico( "" )
    , m_identificadorMedicoAutorizador( "" )
    , m_documentoMedicoAutorizador( "" )
    , m_diagnosticoPrincipal( "" )
    , m_diagnosticoSecundario( "" )
    , m_diagnosticoCausasComplementares( "" )
    , m_diagnosticoCausaMorte( "" )
    , m_codigoSolicitacaoLiberacao( "" )
    , m_nomePaciente( "" )
    , m_dataNascimentoPaciente( "" )
    , m_sexoPaciente( "" )
    , m_racaPaciente( "" )
    , m_nomeMaePaciente( "" )
    , m_nomeResponsavelPaciente( "" )
    , m_tipoDocumentoPaciente( "" )
    , m_etniaIndigena( "" )
    , m_numeroDocumentoPaciente( "" )
    , m_numeroCartaoSaudePaciente( "" )
    , m_nacionalidadePaciente( "" )
    , m_codigoTipoLogradouroPaciente( "" )
    , m_logradouroPaciente( "" )
    , m_numeroLogradouroPaciente( "" )
    , m_complementoEnderecoPaciente( "" )
    , m_bairro( "" )
    , m_municipioEnderecoPaciente( "" )
    , m_ufEnderecoPaciente( "" )
    , m_cepEnderecoPaciente( "" )
    , m_numeroProntuario( "" )
    , m_numeroEnfermaria( "" )
    , m_numeroLeito( "" )
    , m_saidaUtiNeoNatal( "" )
    , m_pesoAoNascer( "" )
    , m_numeroMesesGestacao( "" )
    , m_cnpjEmpregador( "" )
    , m_codigoCBOR( "" )
    , m_codigoCNAER( "" )
    , m_tipoVinculoPrevidencia( "" )
    , m_quantidadeNascidosVivos( "" )
    , m_quantidadeNascidosMortos( "" )
    , m_quantidadeSaidasPorAlta( "" )
    , m_quantidadeSaidasPorTransferencia( "" )
    , m_quantidadeSaidasPorObito( "" )
    , m_numeroFilhos( "" )
    , m_grauInstrucao( "" )
    , m_cidNotificacaoIndicacao( "" )
    , m_tipoMetodoContraceptivo( "" )
    , m_tipoMetodoContraceptivo2( "" )
    , m_gestacaoAltoRisco( "" )
    , m_numeroInscricaoGestantePreNatal( "" )
    , m_aihProcedimentosSecundarios( new AihProcedimentosSecundarios[10] )
{
}

Aih::~Aih()
{
}

void Aih::setNumeroLote( QString valor )
{
    m_numeroLote = valor;
}

void Aih::setQuantidadeLote( QString valor )
{
    m_quantidadeLote = valor;
}

void Aih::setApresentacaoLote( QString valor )
{
    m_apresentacaoLote = valor;
}

void Aih::setSequencialLote( QString valor )
{
    m_sequencialLote = valor;
}

void Aih::setOrgaoEmissor( QString valor )
{
    m_orgaoEmissor = valor;
}

void Aih::setCnesHospital( QString valor )
{
    m_cnesHospital = valor;
}

void Aih::setMunicipioHospital( QString valor )
{
    m_municipioHospital = valor;
}

void Aih::setNumeroAih( QString valor )
{
    m_numeroAih = valor;
}

void Aih::setIdentificacaoAih( QString valor )
{
    m_identificacaoAih = valor;
}

void Aih::setEspecialidadeAih( QString valor )
{
    m_especialidadeAih = valor;
}

void Aih::setModalidadeAih( QString valor )
{
    m_modalidadeAih = valor;
}

void Aih::setSequencialAih( QString valor )
{
    m_sequencialAih = valor;
}

void Aih::setNumeroProximaAih( QString valor )
{
    m_numeroProximaAih = valor;
}

void Aih::setNumeroAnteriorAih( QString valor )
{
    m_numeroAnteriorAih = valor;
}

void Aih::setDataEmissaoAih( QString valor )
{
    m_dataEmissaoAih = valor;
}

void Aih::setDataInternacao( QString valor )
{
    m_dataInternacao = valor;
}

void Aih::setDataSaida( QString valor )
{
    m_dataSaida = valor;
}

void Aih::setProcedimentoSolicitado( QString valor )
{
    m_procedimentoSolicitado = valor;
}

void Aih::setMudancaProcedimento( QString valor )
{
    m_mudancaProcedimento = valor;
}

void Aih::setProcedimentoRealizado( QString valor )
{
    m_procedimentoRealizado = valor;
}

void Aih::setCaraterInternacao( QString valor )
{
    m_caraterInternacao = valor;
}

void Aih::setMotivoSaidaPermanencia( QString valor )
{
    m_motivoSaidaPermanencia = valor;
}

void Aih::setIdentificadorMedicoSolicitante( QString valor )
{
    m_identificadorMedicoSolicitante = valor;
}

void Aih::setDocumentoMedicoSolicitante( QString valor )
{
    m_documentoMedicoSolicitante = valor;
}

void Aih::setIdentificadorMedicoResponsavel( QString valor )
{
    m_identificadorMedicoResponsavel = valor;
}

void Aih::setDocumentoMedicoResponsavel( QString valor )
{
    m_documentoMedicoResponsavel = valor;
}

void Aih::setIdentificadorDiretorClinico( QString valor )
{
    m_identificadorDiretorClinico = valor;
}

void Aih::setDocumentoDiretorClinico( QString valor )
{
    m_documentoDiretorClinico = valor;
}

void Aih::setIdentificadorMedicoAutorizador( QString valor )
{
    m_identificadorMedicoAutorizador = valor;
}

void Aih::setDocumentoMedicoAutorizador( QString valor )
{
    m_documentoMedicoAutorizador = valor;
}

void Aih::setDiagnosticoPrincipal( QString valor )
{
    m_diagnosticoPrincipal = valor;
}

void Aih::setDiagnosticoSecundario( QString valor )
{
    m_diagnosticoSecundario = valor;
}

void Aih::setDiagnosticoCausasComplementares( QString valor )
{
    m_diagnosticoCausasComplementares = valor;
}

void Aih::setDiagnosticoCausaMorte( QString valor )
{
    m_diagnosticoCausaMorte = valor;
}

void Aih::setCodigoSolicitacaoLiberacao( QString valor )
{
    m_codigoSolicitacaoLiberacao = valor;
}

void Aih::setNomePaciente( QString valor )
{
    m_nomePaciente = valor;
}

void Aih::setDataNascimentoPaciente( QString valor )
{
    m_dataNascimentoPaciente = valor;
}

void Aih::setSexoPaciente( QString valor )
{
    m_sexoPaciente = valor;
}

void Aih::setRacaPaciente( QString valor )
{
    m_racaPaciente = valor;
}

void Aih::setNomeMaePaciente( QString valor )
{
    m_nomeMaePaciente = valor;
}

void Aih::setNomeResponsavelPaciente( QString valor )
{
    m_nomeResponsavelPaciente = valor;
}

void Aih::setTipoDocumentoPaciente( QString valor )
{
    m_tipoDocumentoPaciente = valor;
}

void Aih::setEtniaIndigena( QString valor )
{
    m_etniaIndigena = valor;
}

void Aih::setNumeroDocumentoPaciente( QString valor )
{
    m_numeroDocumentoPaciente = valor;
}

void Aih::setNumeroCartaoSaudePaciente( QString valor )
{
    m_numeroCartaoSaudePaciente = valor;
}

void Aih::setNacionalidadePaciente( QString valor )
{
    m_nacionalidadePaciente = valor;
}

void Aih::setCodigoTipoLogradouroPaciente( QString valor )
{
    m_codigoTipoLogradouroPaciente = valor;
}

void Aih::setLogradouroPaciente( QString valor )
{
    m_logradouroPaciente = valor;
}

void Aih::setNumeroLogradouroPaciente( QString valor )
{
    m_numeroLogradouroPaciente = valor;
}

void Aih::setComplementoEnderecoPaciente( QString valor )
{
    m_complementoEnderecoPaciente = valor;
}

void Aih::setBairro( QString valor )
{
    m_bairro = valor;
}

void Aih::setMunicipioEnderecoPaciente( QString valor )
{
    m_municipioEnderecoPaciente = valor;
}

void Aih::setUfEnderecoPaciente( QString valor )
{
    m_ufEnderecoPaciente = valor;
}

void Aih::setCepEnderecoPaciente( QString valor )
{
    m_cepEnderecoPaciente = valor;
}

void Aih::setNumeroProntuario( QString valor )
{
    m_numeroProntuario = valor;
}

void Aih::setNumeroEnfermaria( QString valor )
{
    m_numeroEnfermaria = valor;
}

void Aih::setNumeroLeito( QString valor )
{
    m_numeroLeito = valor;
}

AihProcedimentosSecundarios::AihProcedimentosSecundarios()
    : m_indicadorDocumentoProfissional( "" )
    , m_identificacaoProfissional( "" )
    , m_codigoCBO( "" )
    , m_indicadorEquipe( "" )
    , m_indicadorPrestadorServico( "" )
    , m_identificacaoPrestadorServico( "" )
    , m_indicadorDocumentoExecutor( "" )
    , m_indentificacaoExecutor( "" )
    , m_codigoProcedimento( "" )
    , m_quantidadeProcedimentos( "" )
    , m_competencia( "" )
{
}

AihProcedimentosSecundarios::~AihProcedimentosSecundarios()
{
}

void AihProcedimentosSecundarios::setIndicadorDocumentoProfissional( QString valor )
{
    m_indicadorDocumentoProfissional = valor;
}

void AihProcedimentosSecundarios::setIdentificacaoProfissional( QString valor )
{
    m_identificacaoProfissional = valor;
}

void AihProcedimentosSecundarios::setCodigoCBO( QString valor )
{
    m_codigoCBO = valor;
}

void AihProcedimentosSecundarios::setIndicadorEquipe( QString valor )
{
    m_indicadorEquipe = valor;
}

void AihProcedimentosSecundarios::setIndicadorPrestadorServico( QString valor )
{
    m_indicadorPrestadorServico = valor;
}

void AihProcedimentosSecundarios::setIdentificacaoPrestadorServico( QString valor )
{
    m_identificacaoPrestadorServico = valor;
}

void AihProcedimentosSecundarios::setIndicadorDocumentoExecutor( QString valor )
{
    m_indicadorDocumentoExecutor = valor;
}

void AihProcedimentosSecundarios::setIndentificacaoExecutor( QString valor )
{
    m_indentificacaoExecutor = valor;
}

void AihProcedimentosSecundarios::setCodigoProcedimento( QString valor )
{
    m_codigoProcedimento = valor;
}

void AihProcedimentosSecundarios::setQuantidadeProcedimentos( QString valor )
{
    m_quantidadeProcedimentos = valor;
}

void AihProcedimentosSecundarios::setCompetencia( QString valor )
{
    m_competencia = valor;
}

void Aih::setSaidaUtiNeoNatal( QString valor )
{
    m_saidaUtiNeoNatal = valor;
}

void Aih::setPesoAoNascer( QString valor )
{
    m_pesoAoNascer = valor;
}

void Aih::setNumeroMesesGestacao( QString valor )
{
    m_numeroMesesGestacao = valor;
}

void Aih::setCnpjEmpregador( QString valor )
{
    m_cnpjEmpregador = valor;
}

void Aih::setCodigoCBOR( QString valor )
{
    m_codigoCBOR = valor;
}

void Aih::setCodigoCNAER( QString valor )
{
    m_codigoCNAER = valor;
}

void Aih::setTipoVinculoPrevidencia( QString valor )
{
    m_tipoVinculoPrevidencia = valor;
}

void Aih::setQuantidadeNascidosVivos( QString valor )
{
    m_quantidadeNascidosVivos = valor;
}

void Aih::setQuantidadeNascidosMortos( QString valor )
{
    m_quantidadeNascidosMortos = valor;
}

void Aih::setQuantidadeSaidasPorAlta( QString valor )
{
    m_quantidadeSaidasPorAlta = valor;
}

void Aih::setQuantidadeSaidasPorTransferencia( QString valor )
{
    m_quantidadeSaidasPorTransferencia = valor;
}

void Aih::setQuantidadeSaidasPorObito( QString valor )
{
    m_quantidadeSaidasPorObito = valor;
}

void Aih::setNumeroFilhos( QString valor )
{
    m_numeroFilhos = valor;
}

void Aih::setGrauInstrucao( QString valor )
{
    m_grauInstrucao = valor;
}

void Aih::setCidNotificacaoIndicacao( QString valor )
{
    m_cidNotificacaoIndicacao = valor;
}

void Aih::setTipoMetodoContraceptivo( QString valor )
{
    m_tipoMetodoContraceptivo = valor;
}

void Aih::setTipoMetodoContraceptivo2( QString valor )
{
    m_tipoMetodoContraceptivo2 = valor;
}

void Aih::setGestacaoAltoRisco( QString valor )
{
    m_gestacaoAltoRisco = valor;
}

void Aih::setNumeroInscricaoGestantePreNatal( QString valor )
{
    m_numeroInscricaoGestantePreNatal = valor;
}
