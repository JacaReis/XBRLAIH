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

#ifndef AIH_H
#define AIH_H

#include <QString>

class AihProcedimentosSecundarios
{
public:
    explicit AihProcedimentosSecundarios();
    virtual ~AihProcedimentosSecundarios();

    QString indicadorDocumentoProfissional() const { return m_indicadorDocumentoProfissional; }
    QString identificacaoProfissional() const { return m_identificacaoProfissional; }
    QString codigoCBO() const { return m_codigoCBO; }
    QString indicadorEquipe() const { return m_indicadorEquipe; }
    QString indicadorPrestadorServico() const { return m_indicadorPrestadorServico; }
    QString identificacaoPrestadorServico() const { return m_identificacaoPrestadorServico; }
    QString indicadorDocumentoExecutor() const { return m_indicadorDocumentoExecutor; }
    QString indentificacaoExecutor() const { return m_indentificacaoExecutor; }
    QString codigoProcedimento() const { return m_codigoProcedimento; }
    QString quantidadeProcedimentos() const { return m_quantidadeProcedimentos; }
    QString competencia() const { return m_competencia; }
    QString servico() const {return m_servico ; }
    QString classificacao() const { return m_classificacao; }

    void setIndicadorDocumentoProfissional( QString valor );
    void setIdentificacaoProfissional( QString valor );
    void setCodigoCBO( QString valor );
    void setIndicadorEquipe( QString valor );
    void setIndicadorPrestadorServico( QString valor );
    void setIdentificacaoPrestadorServico( QString valor );
    void setIndicadorDocumentoExecutor( QString valor );
    void setIndentificacaoExecutor( QString valor );
    void setCodigoProcedimento( QString valor );
    void setQuantidadeProcedimentos( QString valor );
    void setCompetencia( QString valor );
    void setServico (QString valor);
    void setClassificacao (QString valor);

private:
    QString m_indicadorDocumentoProfissional;
    QString m_identificacaoProfissional;
    QString m_codigoCBO;
    QString m_indicadorEquipe;
    QString m_indicadorPrestadorServico;
    QString m_identificacaoPrestadorServico;
    QString m_indicadorDocumentoExecutor;
    QString m_indentificacaoExecutor;
    QString m_codigoProcedimento;
    QString m_quantidadeProcedimentos;
    QString m_competencia;
    QString m_servico;
    QString m_classificacao;
};

//Aih principal, de continuacao ou de longa permanencia
class Aih
{
public:
    explicit Aih();
    virtual ~Aih();

    QString numeroLote() const { return m_numeroLote; }
    QString quantidadeLote() const { return m_quantidadeLote; }
    QString apresentacaoLote() const { return m_apresentacaoLote; }
    QString sequencialLote() const { return m_sequencialLote; }
    QString orgaoEmissor() const { return m_orgaoEmissor; }
    QString cnesHospital() const { return m_cnesHospital; }
    QString municipioHospital() const { return m_municipioHospital; }
    QString numeroAih() const { return m_numeroAih; }
    QString identificacaoAih() const { return m_identificacaoAih; }
    QString especialidadeAih() const { return m_especialidadeAih; }
    QString modalidadeAih() const { return m_modalidadeAih; }
    QString sequencialAih() const { return m_sequencialAih; }
    QString numeroProximaAih() const { return m_numeroProximaAih; }
    QString numeroAnteriorAih() const { return m_numeroAnteriorAih; }
    QString dataEmissaoAih() const { return m_dataEmissaoAih; }
    QString dataInternacao() const { return m_dataInternacao; }
    QString dataSaida() const { return m_dataSaida; }
    QString procedimentoSolicitado() const { return m_procedimentoSolicitado; }
    QString mudancaProcedimento() const { return m_mudancaProcedimento; }
    QString procedimentoRealizado() const { return m_procedimentoRealizado; }
    QString caraterInternacao() const { return m_caraterInternacao; }
    QString motivoSaidaPermanencia() const { return m_motivoSaidaPermanencia; }
    QString identificadorMedicoSolicitante() const { return m_identificadorMedicoSolicitante; }
    QString documentoMedicoSolicitante() const { return m_documentoMedicoSolicitante; }
    QString identificadorMedicoResponsavel() const { return m_identificadorMedicoResponsavel; }
    QString documentoMedicoResponsavel() const { return m_documentoMedicoResponsavel; }
    QString identificadorDiretorClinico() const { return m_identificadorDiretorClinico; }
    QString documentoDiretorClinico() const { return m_documentoDiretorClinico; }
    QString identificadorMedicoAutorizador() const { return m_identificadorMedicoAutorizador; }
    QString documentoMedicoAutorizador() const { return m_documentoMedicoAutorizador; }
    QString diagnosticoPrincipal() const { return m_diagnosticoPrincipal; }
    QString diagnosticoSecundario() const { return m_diagnosticoSecundario;}
    QString diagnosticoCausasComplementares() const { return m_diagnosticoCausasComplementares; }
    QString diagnosticoCausaMorte() const { return m_diagnosticoCausaMorte; }
    QString codigoSolicitacaoLiberacao() const { return m_codigoSolicitacaoLiberacao; }
    QString nomePaciente() const { return m_nomePaciente; }
    QString dataNascimentoPaciente() const { return m_dataNascimentoPaciente; }
    QString sexoPaciente() const { return m_sexoPaciente; }
    QString racaPaciente() const { return m_racaPaciente; }
    QString nomeMaePaciente() const { return m_nomeMaePaciente; }
    QString nomeResponsavelPaciente() const { return m_nomeResponsavelPaciente; }
    QString tipoDocumentoPaciente() const { return m_tipoDocumentoPaciente; }
    QString etniaIndigena() const { return m_etniaIndigena; }
    QString numeroDocumentoPaciente() const { return m_numeroDocumentoPaciente; }
    QString numeroCartaoSaudePaciente() const { return m_numeroCartaoSaudePaciente; }
    QString nacionalidadePaciente() const { return m_nacionalidadePaciente; }
    QString codigoTipoLogradouroPaciente() const { return m_codigoTipoLogradouroPaciente; }
    QString logradouroPaciente() const { return m_logradouroPaciente; }
    QString numeroLogradouroPaciente() const { return m_numeroLogradouroPaciente; }
    QString complementoEnderecoPaciente() const { return m_complementoEnderecoPaciente; }
    QString bairro() const { return m_bairro; }
    QString municipioEnderecoPaciente() const { return m_municipioEnderecoPaciente; }
    QString ufEnderecoPaciente() const { return m_ufEnderecoPaciente; }
    QString cepEnderecoPaciente() const { return m_cepEnderecoPaciente; }
    QString numeroProntuario() const { return m_numeroProntuario; }
    QString numeroEnfermaria() const { return m_numeroEnfermaria; }
    QString numeroLeito() const { return m_numeroLeito; }
    AihProcedimentosSecundarios *aihProcedimentosSecundarios( int index ) { return m_aihProcedimentosSecundarios + index; }
    QString saidaUtiNeoNatal() const { return m_saidaUtiNeoNatal; }
    QString pesoAoNascer() const { return m_pesoAoNascer; }
    QString numeroMesesGestacao() const { return m_numeroMesesGestacao; }
    QString cnpjEmpregador() const { return m_cnpjEmpregador; }
    QString codigoCBOR() const { return m_codigoCBOR; }
    QString codigoCNAER() const { return m_codigoCNAER; }
    QString tipoVinculoPrevidencia() const { return m_tipoVinculoPrevidencia; }
    QString quantidadeNascidosVivos() const { return m_quantidadeNascidosVivos; }
    QString quantidadeNascidosMortos() const { return m_quantidadeNascidosMortos; }
    QString quantidadeSaidasPorAlta() const { return m_quantidadeSaidasPorAlta; }
    QString quantidadeSaidasPorTransferencia() const { return m_quantidadeSaidasPorTransferencia; }
    QString quantidadeSaidasPorObito() const { return m_quantidadeSaidasPorObito; }
    QString numeroFilhos() const { return m_numeroFilhos; }
    QString grauInstrucao() const { return m_grauInstrucao; }
    QString cidNotificacaoIndicacao() const { return m_cidNotificacaoIndicacao; }
    QString tipoMetodoContraceptivo() const { return m_tipoMetodoContraceptivo; }
    QString tipoMetodoContraceptivo2() const { return m_tipoMetodoContraceptivo2; }
    QString gestacaoAltoRisco() const { return m_gestacaoAltoRisco; }
    QString numeroInscricaoGestantePreNatal() const { return m_numeroInscricaoGestantePreNatal; }
    QString telefonePacDDD() const {return m_telefonePacDDD; }
    QString telefonePaciente() const {return m_telefonePaciente; }
    QString justificativaCNSPac() const {return m_justificativaCNSPac; }


    void setNumeroLote( QString valor );
    void setQuantidadeLote( QString valor );
    void setApresentacaoLote( QString valor );
    void setSequencialLote( QString valor );
    void setOrgaoEmissor( QString valor );
    void setCnesHospital( QString valor );
    void setMunicipioHospital( QString valor );
    void setNumeroAih( QString valor );
    void setIdentificacaoAih( QString valor );
    void setEspecialidadeAih( QString valor );
    void setModalidadeAih( QString valor );
    void setSequencialAih( QString valor );
    void setNumeroProximaAih( QString valor );
    void setNumeroAnteriorAih( QString valor );
    void setDataEmissaoAih( QString valor );
    void setDataInternacao( QString valor );
    void setDataSaida( QString valor );
    void setProcedimentoSolicitado( QString valor );
    void setMudancaProcedimento( QString valor );
    void setProcedimentoRealizado( QString valor );
    void setCaraterInternacao( QString valor );
    void setMotivoSaidaPermanencia( QString valor );
    void setIdentificadorMedicoSolicitante( QString valor );
    void setDocumentoMedicoSolicitante( QString valor );
    void setIdentificadorMedicoResponsavel( QString valor );
    void setDocumentoMedicoResponsavel( QString valor );
    void setIdentificadorDiretorClinico( QString valor );
    void setDocumentoDiretorClinico( QString valor );
    void setIdentificadorMedicoAutorizador( QString valor );
    void setDocumentoMedicoAutorizador( QString valor );
    void setDiagnosticoPrincipal( QString valor );
    void setDiagnosticoSecundario( QString valor );
    void setDiagnosticoCausasComplementares( QString valor );
    void setDiagnosticoCausaMorte( QString valor );
    void setCodigoSolicitacaoLiberacao( QString valor );
    void setNomePaciente( QString valor );
    void setDataNascimentoPaciente( QString valor );
    void setSexoPaciente( QString valor );
    void setRacaPaciente( QString valor );
    void setNomeMaePaciente( QString valor );
    void setNomeResponsavelPaciente( QString valor );
    void setTipoDocumentoPaciente( QString valor );
    void setEtniaIndigena( QString valor );
    void setNumeroDocumentoPaciente( QString valor );
    void setNumeroCartaoSaudePaciente( QString valor );
    void setNacionalidadePaciente( QString valor );
    void setCodigoTipoLogradouroPaciente( QString valor );
    void setLogradouroPaciente( QString valor );
    void setNumeroLogradouroPaciente( QString valor );
    void setComplementoEnderecoPaciente( QString valor );
    void setBairro( QString valor );
    void setMunicipioEnderecoPaciente( QString valor );
    void setUfEnderecoPaciente( QString valor );
    void setCepEnderecoPaciente( QString valor );
    void setNumeroProntuario( QString valor );
    void setNumeroEnfermaria( QString valor );
    void setNumeroLeito( QString valor );
    void setSaidaUtiNeoNatal( QString valor );
    void setPesoAoNascer( QString valor );
    void setNumeroMesesGestacao( QString valor );
    void setCnpjEmpregador( QString valor );
    void setCodigoCBOR( QString valor );
    void setCodigoCNAER( QString valor );
    void setTipoVinculoPrevidencia( QString valor );
    void setQuantidadeNascidosVivos( QString valor );
    void setQuantidadeNascidosMortos( QString valor );
    void setQuantidadeSaidasPorAlta( QString valor );
    void setQuantidadeSaidasPorTransferencia( QString valor );
    void setQuantidadeSaidasPorObito( QString valor );
    void setNumeroFilhos( QString valor );
    void setGrauInstrucao( QString valor );
    void setCidNotificacaoIndicacao( QString valor );
    void setTipoMetodoContraceptivo( QString valor );
    void setTipoMetodoContraceptivo2( QString valor );
    void setGestacaoAltoRisco( QString valor );
    void setNumeroInscricaoGestantePreNatal( QString valor );
    void setTelefonePacDDD(QString valor);
    void setTelefonePaciente(QString valor);
    void setJustificativaCNSPac (QString valor);

private:
    QString m_numeroLote;
    QString m_quantidadeLote;
    QString m_apresentacaoLote;
    QString m_sequencialLote;
    QString m_orgaoEmissor;
    QString m_cnesHospital;
    QString m_municipioHospital;
    QString m_numeroAih;
    QString m_identificacaoAih;
    QString m_especialidadeAih;
    QString m_modalidadeAih;
    QString m_sequencialAih;
    QString m_numeroProximaAih;
    QString m_numeroAnteriorAih;
    QString m_dataEmissaoAih;
    QString m_dataInternacao;
    QString m_dataSaida;
    QString m_procedimentoSolicitado;
    QString m_mudancaProcedimento;
    QString m_procedimentoRealizado;
    QString m_caraterInternacao;
    QString m_motivoSaidaPermanencia;
    QString m_identificadorMedicoSolicitante;
    QString m_documentoMedicoSolicitante;
    QString m_identificadorMedicoResponsavel;
    QString m_documentoMedicoResponsavel;
    QString m_identificadorDiretorClinico;
    QString m_documentoDiretorClinico;
    QString m_identificadorMedicoAutorizador;
    QString m_documentoMedicoAutorizador;
    QString m_diagnosticoPrincipal;
    QString m_diagnosticoSecundario;
    QString m_diagnosticoCausasComplementares;
    QString m_diagnosticoCausaMorte;
    QString m_codigoSolicitacaoLiberacao;
    QString m_nomePaciente;
    QString m_dataNascimentoPaciente;
    QString m_sexoPaciente;
    QString m_racaPaciente;
    QString m_nomeMaePaciente;
    QString m_nomeResponsavelPaciente;
    QString m_tipoDocumentoPaciente;
    QString m_etniaIndigena;
    //----
    QString m_numeroDocumentoPaciente;
    QString m_numeroCartaoSaudePaciente;
    QString m_nacionalidadePaciente;
    QString m_codigoTipoLogradouroPaciente;
    QString m_logradouroPaciente;
    QString m_numeroLogradouroPaciente;
    QString m_complementoEnderecoPaciente;
    QString m_bairro;
    QString m_municipioEnderecoPaciente;
    QString m_ufEnderecoPaciente;
    QString m_cepEnderecoPaciente;
    QString m_numeroProntuario;
    QString m_numeroEnfermaria;
    QString m_numeroLeito;
    QString m_saidaUtiNeoNatal;
    QString m_pesoAoNascer;
    QString m_numeroMesesGestacao;
    QString m_cnpjEmpregador;
    QString m_codigoCBOR;
    QString m_codigoCNAER;
    QString m_tipoVinculoPrevidencia;
    QString m_quantidadeNascidosVivos;
    QString m_quantidadeNascidosMortos;
    QString m_quantidadeSaidasPorAlta;
    QString m_quantidadeSaidasPorTransferencia;
    QString m_quantidadeSaidasPorObito;
    QString m_numeroFilhos;
    QString m_grauInstrucao;
    QString m_cidNotificacaoIndicacao;
    QString m_tipoMetodoContraceptivo;
    QString m_tipoMetodoContraceptivo2;
    QString m_gestacaoAltoRisco;
    QString m_numeroInscricaoGestantePreNatal;
    AihProcedimentosSecundarios *m_aihProcedimentosSecundarios;
    QString m_telefonePacDDD;
    QString m_telefonePaciente;
    QString m_justificativaCNSPac;
};

#endif // AIH_H
