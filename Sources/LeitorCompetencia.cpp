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

#include "Headers/Financiamento.h"
#include "Headers/LeitorCompetencia.h"
#include "Headers/LeitorFinanciamento.h"
#include "Headers/LeitorProcedimento.h"
#include "Headers/LeitorRubrica.h"
#include "Headers/Procedimento.h"
#include "Headers/Rubrica.h"

#include <QDir>
#include <QList>
#include <QMap>

#include <QDebug>

LeitorCompetencia::LeitorCompetencia( QString caminhoDiretorio, QObject *parent )
    : QObject( parent )
    , m_caminhoFinanciamento ( QDir( caminhoDiretorio ).filePath( QString ( "tb_financiamento.txt" ) ) )
    , m_caminhoProcedimento ( QDir( caminhoDiretorio ).filePath( QString ( "tb_procedimento.txt" ) ) )
    , m_caminhoRubrica ( QDir( caminhoDiretorio ).filePath( QString( "tb_rubrica.txt" ) ) )
{
    m_leitorFinanciamento = new LeitorFinanciamento( m_caminhoFinanciamento );
    m_leitorProcedimento = new LeitorProcedimento( m_caminhoProcedimento );
    m_leitorRubrica = new LeitorRubrica( m_caminhoRubrica );
}

LeitorCompetencia::~LeitorCompetencia()
{
    delete m_leitorFinanciamento;
    delete m_leitorProcedimento;
    delete m_leitorRubrica;
}

bool LeitorCompetencia::abrirCompetencia()
{
    if ( m_leitorFinanciamento->abrirFinanciamentos() )
        m_leitorFinanciamento->lerFinanciamentos();
    else
        return false;

    if ( m_leitorProcedimento->abrirProcedimentos() )
        m_leitorProcedimento->lerProcedimentos();
    else
        return false;

    if ( m_leitorRubrica->abrirRubricas() )
        m_leitorRubrica->lerRubricas();
    else
        return false;

    return true;
}

void LeitorCompetencia::inicializarCompetencia()
{
    const QList<Procedimento *> procedimentos = m_leitorProcedimento->procedimentos();
    const QList<Financiamento *> financiamentos = m_leitorFinanciamento->financiamentos();
    const QList<Rubrica *> rubricas = m_leitorRubrica->rubricas();

    QMap<QString, Financiamento *> mapeamentoFinanciamentos;
    QMap<QString, Rubrica *> mapeamentoRubricas;

    foreach( Financiamento *financiamentoTemp, financiamentos )
        mapeamentoFinanciamentos.insert( financiamentoTemp->codigoFinanciamento(), financiamentoTemp );

    foreach( Rubrica *rubricaTemp, rubricas )
        mapeamentoRubricas.insert( rubricaTemp->codigoRubrica(), rubricaTemp );

    foreach ( Procedimento *procedimentoTemp, procedimentos )
    {
        procedimentoTemp->setRubrica( mapeamentoRubricas.value( procedimentoTemp->codigoRubrica() ) );
        procedimentoTemp->setFinanciamento( mapeamentoFinanciamentos.value( procedimentoTemp->codigoFinanciamento() ) );
    }

    emit competenciaCarregada();
}

const QList<Procedimento *> LeitorCompetencia::procedimentos()
{
    return m_leitorProcedimento->procedimentos();
}
