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

#ifndef RUBRICA_H
#define RUBRICA_H

#include <QString>

class Rubrica
{
public:
    explicit Rubrica();
    virtual ~Rubrica();

    QString codigoRubrica() const { return m_codigoRubrica; }
    QString numeroRubrica() const { return m_numeroRubrica; }
    QString dataCompetencia() const { return m_dataCompetencia; }

    void setCodigoRubrica( QString valor );
    void setNumeroRubrica( QString valor );
    void setDataCompetencia( QString valor );

private:
    QString m_codigoRubrica;
    QString m_numeroRubrica;
    QString m_dataCompetencia;
};

#endif // RUBRICA_H
