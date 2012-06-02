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

#ifndef LEITORRUBRICA_H
#define LEITORRUBRICA_H

#include <QList>
#include <QString>

class Rubrica;

class QFile;
class QTextStream;

class LeitorRubrica
{
public:
    explicit LeitorRubrica( QString caminhoRubrica );
    virtual ~LeitorRubrica();

    bool abrirRubricas();
    void lerRubricas();

    const QList<Rubrica *> rubricas() const { return m_rubricas; }

private:
    QFile *m_arquivoRubrica;
    QTextStream *m_rubricaStream;
    QList<Rubrica *> m_rubricas;

    void inicializarRubrica( Rubrica *rubrica );
};

#endif // LEITORRUBRICA_H
