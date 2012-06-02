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

#ifndef LEITORFINANCIAMENTO_H
#define LEITORFINANCIAMENTO_H

#include <QList>
#include <QString>

class Financiamento;

class QFile;
class QTextStream;

class LeitorFinanciamento
{
public:
    explicit LeitorFinanciamento( QString caminhoFinanciamento );
    virtual ~LeitorFinanciamento();

    bool abrirFinanciamentos();
    void lerFinanciamentos();

    const QList<Financiamento *> financiamentos() const { return m_financiamentos; }

private:
    QFile *m_arquivoFinanciamento;
    QTextStream *m_financiamentoStream;
    QList<Financiamento *> m_financiamentos;

    void inicializarFinanciamento( Financiamento *financiamento );
};

#endif // LEITORFINANCIAMENTO_H
