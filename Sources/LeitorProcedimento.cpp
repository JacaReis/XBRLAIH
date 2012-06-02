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

#include "Headers/LeitorProcedimento.h"

#include "Headers/Procedimento.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

LeitorProcedimento::LeitorProcedimento( QString caminhoProcedimento )
    : m_arquivoProcedimento( new QFile( caminhoProcedimento ) )
{
}

LeitorProcedimento::~LeitorProcedimento()
{
    m_arquivoProcedimento->close();
    m_procedimentos.clear();

    delete m_arquivoProcedimento;
    delete m_procedimentoStream;
}

bool LeitorProcedimento::abrirProcedimentos()
{
    if ( !m_arquivoProcedimento->open( QIODevice::ReadOnly | QIODevice::Text ) )
        return false;

    m_procedimentoStream = new QTextStream ( m_arquivoProcedimento );
    m_procedimentoStream->setCodec( "UTF-8" );
    return true;
}

void LeitorProcedimento::lerProcedimentos()
{
    if ( !m_procedimentos.isEmpty() )
        return;

    Procedimento *procedimento;

    while ( !m_procedimentoStream->atEnd() )
    {
        procedimento = new Procedimento();
        inicializarProcedimento( procedimento );

        if ( procedimento )
            m_procedimentos.append( procedimento );
    }
}

void LeitorProcedimento::inicializarProcedimento( Procedimento *procedimento )
{
    procedimento->setCodigoProcedimento( m_procedimentoStream->read( 10 ) );
    procedimento->setNomeProcedimento( m_procedimentoStream->read( 250 ) );
    procedimento->setTipoComplexidade( m_procedimentoStream->read( 1 ) );
    procedimento->setTipoSexo( m_procedimentoStream->read( 1 ) );
    procedimento->setQuantidadeMaximaExecucao( m_procedimentoStream->read( 4 ) );
    procedimento->setQuantidadeDiasPermanencia( m_procedimentoStream->read( 4 ) );
    procedimento->setQuantidadePontos( m_procedimentoStream->read( 4 ) );
    procedimento->setValorIdadeMinima( m_procedimentoStream->read( 4 ) );
    procedimento->setValorIdadeMaxima( m_procedimentoStream->read( 4 ) );
    procedimento->setValorSh( converterStrParaDouble( m_procedimentoStream->read( 10 ) ) );
    procedimento->setValorSa( converterStrParaDouble( m_procedimentoStream->read( 10 ) ) );
    procedimento->setValorSp( converterStrParaDouble( m_procedimentoStream->read( 10 ) ) );
    procedimento->setCodigoFinanciamento( m_procedimentoStream->read( 2 ) );
    procedimento->setCodigoRubrica( m_procedimentoStream->read( 6 ) );
    procedimento->setDataCompetencia( m_procedimentoStream->read( 6 ) );
    m_procedimentoStream->read( 1 );
}

double LeitorProcedimento::converterStrParaDouble( QString valor )
{
    double parteInteira = valor.mid( 1, 7 ).toDouble();
    double parteDecimal = valor.mid( 8, 2 ).toDouble();

    return parteInteira + ( parteDecimal / 100 );
}

