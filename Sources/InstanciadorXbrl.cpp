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

#include "Headers/InstanciadorXbrl.h"

#include "Headers/GeradorEstatistica.h"

#include <QDate>
#include <QFile>
#include <QLocale>
#include <QXmlStreamWriter>

#include <QDebug>

InstanciadorXbrl::InstanciadorXbrl( QString caminhoXml,
                                    GeradorEstatistica *geradorEstatistica,
                                    QString caminhoTaxonomia,
                                    QObject *parent )
    : QObject( parent )
    , m_arquivoXml( new QFile( caminhoXml ) )
    , m_caminhoTaxonomia( caminhoTaxonomia )
    , m_geradorEstatistica( geradorEstatistica )
{
}

InstanciadorXbrl::~InstanciadorXbrl()
{
    delete m_arquivoXml;
    delete m_xmlStream;
}

bool InstanciadorXbrl::criarXml()
{
    if ( !m_arquivoXml->open( QIODevice::WriteOnly | QIODevice::Text ) )
        return false;

    m_xmlStream = new QXmlStreamWriter( m_arquivoXml );
    m_xmlStream->setAutoFormatting( true );
    return true;
}

void InstanciadorXbrl::preencherXbrl()
{       
    QDate dataInicial( m_geradorEstatistica->anoCompetencia(),
                       m_geradorEstatistica->mesCompetencia(),
                       1 );

    QDate dataFinal( dataInicial.year(),
                     dataInicial.month(),
                     dataInicial.daysInMonth() );

    //Media Complexidade
    double mediaCAtencaoBasica =
                m_geradorEstatistica->mediaComplexidadeTotalAtencaoBasica();

    double mediaCMediaAltaComplexidade =
                m_geradorEstatistica->mediaComplexidadeTotalMediaAltaComplexidade();

    double mediaCFaec =
                m_geradorEstatistica->mediaComplexidadeTotalFaec();

    double mediaCTotal = mediaCAtencaoBasica +
                      mediaCMediaAltaComplexidade +
                      mediaCFaec;

    //Alta Complexidade
    double altaCAtencaoBasica =
                m_geradorEstatistica->altaComplexidadeTotalAtencaoBasica();

    double altaCMediaAltaComplexidade =
                m_geradorEstatistica->altaComplexidadeTotalMediaAltaComplexidade();

    double altaCFaec =
                m_geradorEstatistica->altaComplexidadeTotalFaec();

    double altaCTotal = altaCAtencaoBasica +
                     altaCMediaAltaComplexidade +
                     altaCFaec;

    //Totais
    double totalMediaAltaComplexidade = mediaCMediaAltaComplexidade + altaCMediaAltaComplexidade;
    double totalFaec = mediaCFaec + altaCFaec;
    double totalAtencaoBasica = mediaCAtencaoBasica + altaCAtencaoBasica;
    double totalGeral = mediaCTotal + altaCTotal;

    m_xmlStream->writeStartDocument();

    m_xmlStream->writeStartElement( "xbrli:xbrl" );
    m_xmlStream->writeAttribute( "xmlns:n1", "http://www.hc.com" );
    m_xmlStream->writeAttribute( "xmlns:xlink", "http://www.w3.org/1999/xlink" );
    m_xmlStream->writeAttribute( "xmlns:xl", "http://www.xbrl.org/2003/XLink" );
    m_xmlStream->writeAttribute( "xmlns:xbrli", "http://www.xbrl.org/2003/instance" );
    m_xmlStream->writeAttribute( "xmlns:link", "http://www.xbrl.org/2003/linkbase" );
    m_xmlStream->writeAttribute( "xmlns:ref", "http://www.xbrl.org/2004/ref" );
    m_xmlStream->writeAttribute( "xmlns:xbrldt", "http://xbrl.org/2005/xbrldt" );
    m_xmlStream->writeAttribute( "xmlns:iso4217", "http://www.xbrl.org/2003/iso4217" );

    m_xmlStream->writeStartElement( "link:schemaRef" );
    m_xmlStream->writeAttribute( "xlink:type", "simple" );
    m_xmlStream->writeAttribute( "xlink:href", m_caminhoTaxonomia );
    m_xmlStream->writeEndElement(); // link:schemaRef

    m_xmlStream->writeStartElement( "xbrli:context" );
    m_xmlStream->writeAttribute( "id", "ctx1" );

    m_xmlStream->writeStartElement( "xbrli:entity" );
    m_xmlStream->writeStartElement( "xbrli:identifier" );
    m_xmlStream->writeAttribute( "scheme", "hc" );
    m_xmlStream->writeCharacters( "http://www.hc.com" );
    m_xmlStream->writeEndElement(); // xbrli:identifier
    m_xmlStream->writeEndElement(); // xbrli:entity

    m_xmlStream->writeStartElement( "xbrli:period" );
    m_xmlStream->writeTextElement( "xbrli:startDate", dataInicial.toString( Qt::ISODate ) );
    m_xmlStream->writeTextElement( "xbrli:endDate", dataFinal.toString( Qt::ISODate ) );
    m_xmlStream->writeEndElement(); // xbrli:period

    m_xmlStream->writeEndElement(); // xbrli:context

    m_xmlStream->writeStartElement( "xbrli:unit" );
    m_xmlStream->writeAttribute( "id", "BRL" );
    m_xmlStream->writeTextElement( "xbrli:measure", dataInicial.toString( Qt::ISODate ) );
    m_xmlStream->writeEndElement(); // xbrli:unit

    m_xmlStream->writeStartElement( "n1:valorMediaCAtencaoBasica" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( mediaCAtencaoBasica, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorMediaCAtencaoBasica

    m_xmlStream->writeStartElement( "n1:valorMediaCMediaAltaComplexidade" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( mediaCMediaAltaComplexidade, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorMediaCMediaAltaComplexidade

    m_xmlStream->writeStartElement( "n1:valorMediaCFaec" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( mediaCFaec, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorMediaCFaec

    m_xmlStream->writeStartElement( "n1:valorMediaCTotal" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( mediaCTotal, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorMediaCTotal

    m_xmlStream->writeStartElement( "n1:valorAltaCAtencaoBasica" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( altaCAtencaoBasica, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorAltaCAtencaoBasica

    m_xmlStream->writeStartElement( "n1:valorAltaCMediaAltaComplexidade" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( altaCMediaAltaComplexidade, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorAltaCMediaAltaComplexidade

    m_xmlStream->writeStartElement( "n1:valorAltaCFaec" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( altaCFaec, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorAltaCFaec

    m_xmlStream->writeStartElement( "n1:valorAltaCTotal" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( altaCTotal, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:valorAltaCTotal

    m_xmlStream->writeStartElement( "n1:totalMediaAltaComplexidade" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( totalMediaAltaComplexidade, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:totalMediaAltaComplexidade

    m_xmlStream->writeStartElement( "n1:totalFaec" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( totalFaec, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:totalFaec

    m_xmlStream->writeStartElement( "n1:totalAtencaoBasica" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( totalAtencaoBasica, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:totalAtencaoBasica

    m_xmlStream->writeStartElement( "n1:totalGeral" );
    m_xmlStream->writeAttribute( "unitRef", "BRL" );
    m_xmlStream->writeAttribute( "decimals", "3" );
    m_xmlStream->writeAttribute( "contextRef", "ctx1" );
    m_xmlStream->writeCharacters( QLocale::system().toString( totalGeral, 'f', 3 ) );
    m_xmlStream->writeEndElement(); // n1:totalGeral

    m_xmlStream->writeEndElement(); // xbrli:xbrl

    m_xmlStream->writeEndDocument();

    m_arquivoXml->close();

    emit xbrlPreenchido( m_arquivoXml->fileName() );
}
