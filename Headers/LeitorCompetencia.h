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

#ifndef LEITORGERALARQUIVOS_H
#define LEITORGERALARQUIVOS_H

#include <QObject>
#include <QString>

class Financiamento;
class LeitorFinanciamento;
class LeitorProcedimento;
class LeitorRubrica;
class Procedimento;
class Rubrica;

class LeitorCompetencia : public QObject
{
    Q_OBJECT

public:
    explicit LeitorCompetencia( QString caminhoDiretorio, QObject *parent = 0 );
    virtual ~LeitorCompetencia();

    bool abrirCompetencia();
    void inicializarCompetencia();

    const QList<Procedimento *> procedimentos();

signals:
    void competenciaCarregada();

private:
    LeitorFinanciamento *m_leitorFinanciamento;
    LeitorProcedimento *m_leitorProcedimento;
    LeitorRubrica *m_leitorRubrica;

    QString m_caminhoFinanciamento;
    QString m_caminhoProcedimento;
    QString m_caminhoRubrica;
};

#endif // LEITORGERALARQUIVOS_H
