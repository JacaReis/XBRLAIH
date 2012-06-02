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

#include "Headers/GeradorEstatistica.h"

#include "Headers/Aih.h"
#include "Headers/Financiamento.h"
#include "Headers/Procedimento.h"

#include <QDebug>

GeradorEstatistica::GeradorEstatistica( const QList<Aih *> aihs,
                                        const QList<Procedimento *> procedimentos,
                                        QObject *parent )
    : QObject( parent )
    , m_aihs( aihs )
{
    QMap<QString, Procedimento *> mapaProcedimentos;

    foreach( Procedimento *procedimento, procedimentos )
    {
        mapaProcedimentos.insert( procedimento->codigoProcedimento(), procedimento );
    }

    foreach( Aih *aih, m_aihs )
    {
        for( int i = 0; i < 10; ++i )
        {
            Procedimento *procedimentoTemp = mapaProcedimentos.value(
                        aih->aihProcedimentosSecundarios( i )->
                        codigoProcedimento() );

            if( !procedimentoTemp ) continue;
            m_procedimentos.append( procedimentoTemp );
        }
    }
}

GeradorEstatistica::~GeradorEstatistica()
{
}

double GeradorEstatistica::mediaComplexidadeTotalAtencaoBasica()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "01" )
             && ( procedimento->tipoComplexidade() == "2" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "mediaComplexidadeTotalAtencaoBasica() " << resultado;
    return resultado;
}

double GeradorEstatistica::mediaComplexidadeTotalFaec()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "04" )
             && ( procedimento->tipoComplexidade() == "2" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "mediaComplexidadeTotalFaec() " << resultado;
    return resultado;
}

double GeradorEstatistica::mediaComplexidadeTotalMediaAltaComplexidade()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "06" )
             && ( procedimento->tipoComplexidade() == "2" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "mediaComplexidadeTotalMediaAltaComplexidade() " << resultado;
    return resultado;
}

double GeradorEstatistica::altaComplexidadeTotalAtencaoBasica()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "01" )
             && ( procedimento->tipoComplexidade() == "3" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "altaComplexidadeTotalAtencaoBasica() " << resultado;
    return resultado;
}

double GeradorEstatistica::altaComplexidadeTotalFaec()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "04" )
             && ( procedimento->tipoComplexidade() == "3" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "altaComplexidadeTotalFaec() " << resultado;
    return resultado;
}

double GeradorEstatistica::altaComplexidadeTotalMediaAltaComplexidade()
{
    double resultado = 0;

    foreach( Procedimento *procedimento, m_procedimentos )
    {
        if ( ( procedimento->financiamento()->codigoFinanciamento() == "06" )
             && ( procedimento->tipoComplexidade() == "3" ) )
        {
            resultado += procedimento->valorSa() +
                         procedimento->valorSh() +
                         procedimento->valorSp();
        }

    }

    qDebug() << "altaComplexidadeTotalMediaAltaComplexidade() " << resultado;
    return resultado;
}

int GeradorEstatistica::anoCompetencia()
{
    return m_procedimentos.first()->dataCompetencia().mid( 0, 4 ).toInt();
}

int GeradorEstatistica::mesCompetencia()
{
    return m_procedimentos.first()->dataCompetencia().mid( 4, 2 ).toInt();
}

int GeradorEstatistica::anoApresentacaoLote()
{
    return m_aihs.first()->apresentacaoLote().mid( 0, 4 ).toInt();
}

int GeradorEstatistica::mesApresentacaolote()
{
    return m_aihs.first()->apresentacaoLote().mid( 4, 2 ).toInt();
}

bool GeradorEstatistica::datasConferem()
{
    return ( mesApresentacaolote() == mesCompetencia() ) &&
            ( anoApresentacaoLote() == anoCompetencia() );
}


