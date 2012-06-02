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

#ifndef FINANCIAMENTO_H
#define FINANCIAMENTO_H

#include <QString>

class Financiamento
{
public:
    explicit Financiamento();
    virtual ~Financiamento();

    QString codigoFinanciamento() const { return m_codigoFinanciamento; }
    QString nomeFinanciamento() const { return m_nomeFinanciamento; }
    QString dataCompetencia() const { return m_dataCompetencia; }

    void setCodigoFinanciamento( QString valor );
    void setNomeFinanciamento( QString valor );
    void setDataCompetencia( QString valor );

private:
    QString m_codigoFinanciamento;
    QString m_nomeFinanciamento;
    QString m_dataCompetencia;
};

#endif // FINANCIAMENTO_H
