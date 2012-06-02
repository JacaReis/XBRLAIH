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

#include "Headers/Procedimento.h"

Procedimento::Procedimento()
{
}

Procedimento::~Procedimento()
{
}

void Procedimento::setCodigoProcedimento( QString valor )
{
    m_codigoProcedimento = valor;
}

void Procedimento::setNomeProcedimento( QString valor )
{
    m_nomeProcedimento = valor;
}

void Procedimento::setTipoComplexidade( QString valor )
{
    m_tipoComplexidade = valor;
}

void Procedimento::setTipoSexo( QString valor )
{
    m_tipoSexo = valor;
}

void Procedimento::setQuantidadeMaximaExecucao( QString valor )
{
    m_quantidadeMaximaExecucao = valor;
}

void Procedimento::setQuantidadeDiasPermanencia( QString valor )
{
    m_quantidadeDiasPermanencia = valor;
}

void Procedimento::setQuantidadePontos( QString valor )
{
    m_quantidadePontos = valor;
}

void Procedimento::setValorIdadeMinima( QString valor )
{
    m_idadeMinima = valor;
}

void Procedimento::setValorIdadeMaxima( QString valor )
{
    m_idadeMaxima = valor;
}

void Procedimento::setValorSh( double valor )
{
    m_valorSh = valor;
}

void Procedimento::setValorSa( double valor )
{
    m_valorSa = valor;
}

void Procedimento::setValorSp( double valor )
{
    m_valorSp = valor;
}

void Procedimento::setCodigoFinanciamento( QString valor )
{
    m_codigoFinanciamento = valor;
}

void Procedimento::setCodigoRubrica( QString valor )
{
    m_codigoRubrica = valor;
}

void Procedimento::setDataCompetencia( QString valor )
{
    m_dataCompetencia = valor;
}

void Procedimento::setRubrica( Rubrica *rubrica )
{
    m_rubrica = rubrica;
}

void Procedimento::setFinanciamento( Financiamento *financiamento )
{
    m_financiamento = financiamento;
}
