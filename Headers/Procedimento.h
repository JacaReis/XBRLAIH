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

#ifndef PROCEDIMENTO_H
#define PROCEDIMENTO_H

#include <QString>

class Financiamento;
class Rubrica;

class Procedimento
{
public:
    explicit Procedimento();
    virtual ~Procedimento();

    QString codigoProcedimento() const { return m_codigoProcedimento; }
    QString nomeProcedimento() const { return m_nomeProcedimento; }
    QString tipoComplexidade() const { return m_tipoComplexidade; }
    QString tipoSexo() const { return m_tipoSexo; }
    QString quantidadeMaximaExecucao() const { return m_quantidadeMaximaExecucao; }
    QString quantidadeDiasPermanencia() const { return m_quantidadeDiasPermanencia; }
    QString quantidadePontos() const { return m_quantidadePontos; }
    QString idadeMinima() const { return m_idadeMinima; }
    QString idadeMaxima() const { return m_idadeMaxima; }
    double valorSh() const { return m_valorSh; }
    double valorSa() const { return m_valorSa; }
    double valorSp() const { return m_valorSp; }
    QString codigoFinanciamento() const { return m_codigoFinanciamento; }
    QString codigoRubrica() const { return m_codigoRubrica; }
    QString dataCompetencia() const { return m_dataCompetencia; }
    Rubrica *rubrica() const { return m_rubrica; }
    Financiamento *financiamento() { return m_financiamento; }

    void setCodigoProcedimento( QString valor );
    void setNomeProcedimento( QString valor );
    void setTipoComplexidade( QString valor );
    void setTipoSexo( QString valor );
    void setQuantidadeMaximaExecucao( QString valor );
    void setQuantidadeDiasPermanencia( QString valor );
    void setQuantidadePontos( QString valor );
    void setValorIdadeMinima( QString valor );
    void setValorIdadeMaxima( QString valor );
    void setValorSh( double valor );
    void setValorSa( double valor );
    void setValorSp( double valor );
    void setCodigoFinanciamento( QString valor );
    void setCodigoRubrica( QString valor );
    void setDataCompetencia( QString valor );
    void setRubrica( Rubrica *rubrica );
    void setFinanciamento( Financiamento *financiamneto );

private:
    QString m_codigoProcedimento;
    QString m_nomeProcedimento;
    QString m_tipoComplexidade; //Alta Complexidade, Atencao Basica, Media Complexidade, Nao se aplica
    QString m_tipoSexo;
    QString m_quantidadeMaximaExecucao;
    QString m_quantidadeDiasPermanencia;
    QString m_quantidadePontos;
    QString m_idadeMinima;
    QString m_idadeMaxima;
    double m_valorSh;
    double m_valorSa;
    double m_valorSp;
    QString m_codigoFinanciamento;
    QString m_codigoRubrica;
    QString m_dataCompetencia;
    Rubrica *m_rubrica;
    Financiamento *m_financiamento;
};

#endif // PROCEDIMENTO_H
