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

#include "Headers/LeitorRubrica.h"

#include "Headers/Rubrica.h"

#include <QFile>
#include <QTextStream>

LeitorRubrica::LeitorRubrica( QString caminhoRubrica )
    : m_arquivoRubrica ( new QFile ( caminhoRubrica ) )
{
}

LeitorRubrica::~LeitorRubrica()
{
    m_arquivoRubrica->close();
    m_rubricas.clear();

    delete m_arquivoRubrica;
    delete m_rubricaStream;
}

bool LeitorRubrica::abrirRubricas()
{
    if ( !m_arquivoRubrica->open( QIODevice::ReadOnly | QIODevice::Text ) )
        return false;

    m_rubricaStream = new QTextStream( m_arquivoRubrica );
    m_rubricaStream->setCodec( "UTF-8" );
    return true;
}

void LeitorRubrica::lerRubricas()
{
    if ( !m_rubricas.isEmpty() )
        return;

    Rubrica *rubrica;

    while ( !m_rubricaStream->atEnd() )
    {
        rubrica = new Rubrica();
        inicializarRubrica( rubrica );

        if ( rubrica )
            m_rubricas.append( rubrica );
    }
}

void LeitorRubrica::inicializarRubrica( Rubrica *rubrica )
{
    rubrica->setCodigoRubrica( m_rubricaStream->read( 6 ) );
    rubrica->setNumeroRubrica( m_rubricaStream->read( 100 ) );
    rubrica->setDataCompetencia( m_rubricaStream->read( 6 ) );
    m_rubricaStream->read( 1 );
}

