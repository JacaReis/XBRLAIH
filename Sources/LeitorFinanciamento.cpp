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

#include "Headers/LeitorFinanciamento.h"

#include "Headers/Financiamento.h"

#include <QFile>
#include <QTextStream>

LeitorFinanciamento::LeitorFinanciamento( QString caminhoFinanciamento )
    : m_arquivoFinanciamento( new QFile ( caminhoFinanciamento ) )
{
}

LeitorFinanciamento::~LeitorFinanciamento()
{
    m_arquivoFinanciamento->close();
    m_financiamentos.clear();

    delete m_arquivoFinanciamento;
    delete m_financiamentoStream;
}

bool LeitorFinanciamento::abrirFinanciamentos()
{
    if( !m_arquivoFinanciamento->open( QIODevice::ReadOnly | QIODevice::Text ) )
        return false;

    m_financiamentoStream = new QTextStream( m_arquivoFinanciamento );
    m_financiamentoStream->setCodec( "UTF-8" );
    return true;
}

void LeitorFinanciamento::lerFinanciamentos()
{
    if ( !m_financiamentos.isEmpty() )
        return;

    Financiamento *financiamento;

    while( !m_financiamentoStream->atEnd() )
    {
        financiamento = new Financiamento();
        inicializarFinanciamento( financiamento );

        if ( financiamento )
            m_financiamentos.append( financiamento );
    }
}

void LeitorFinanciamento::inicializarFinanciamento( Financiamento *financiamento )
{
    financiamento->setCodigoFinanciamento( m_financiamentoStream->read( 2 ) );
    financiamento->setNomeFinanciamento( m_financiamentoStream->read( 100 ) );
    financiamento->setDataCompetencia( m_financiamentoStream->read( 6 ) );
    m_financiamentoStream->read( 1 ); // filler
}
