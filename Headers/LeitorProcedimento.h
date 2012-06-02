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

#ifndef LEITORPROCEDIMENTO_H
#define LEITORPROCEDIMENTO_H

#include <QList>
#include <QString>

class Procedimento;

class QFile;
class QTextStream;

class LeitorProcedimento
{
public:
    explicit LeitorProcedimento( QString caminhoProcedimento );
    virtual ~LeitorProcedimento();

    bool abrirProcedimentos();
    void lerProcedimentos();

    const QList<Procedimento *> procedimentos() const { return m_procedimentos; }

private:
    QFile *m_arquivoProcedimento;
    QTextStream *m_procedimentoStream;
    QList<Procedimento *> m_procedimentos;

    void inicializarProcedimento( Procedimento *procedimento );
    double converterStrParaDouble( QString valor );
};

#endif // LEITORPROCEDIMENTO_H
