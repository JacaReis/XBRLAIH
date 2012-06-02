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

#ifndef GERADORESTATISTICA_H
#define GERADORESTATISTICA_H

#include <QObject>
#include <QMap>

class Aih;
class Procedimento;

class GeradorEstatistica : public QObject
{
    Q_OBJECT

public:
    explicit GeradorEstatistica( const QList<Aih *> aihs,
                                 const QList<Procedimento *> procedimentos,
                                 QObject *parent = 0 );
    virtual ~GeradorEstatistica();

    double mediaComplexidadeTotalAtencaoBasica();
    double mediaComplexidadeTotalFaec();
    double mediaComplexidadeTotalMediaAltaComplexidade();

    double altaComplexidadeTotalAtencaoBasica();
    double altaComplexidadeTotalFaec();
    double altaComplexidadeTotalMediaAltaComplexidade();

    int anoCompetencia();
    int mesCompetencia();

    int anoApresentacaoLote();
    int mesApresentacaolote();

    bool datasConferem();

signals:
    
public slots:

private:
    const QList<Aih *> m_aihs;
    QList<Procedimento *> m_procedimentos;
};

#endif // GERADORESTATISTICA_H
