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

#ifndef BACKUPREADER_H
#define BACKUPREADER_H

#include <QObject>
#include <QString>

class Aih;
class QFile;
class QTextStream;

class LeitorBackup : public QObject
{
    Q_OBJECT

public:
    explicit LeitorBackup( QString caminhoBackup, QObject *parent = 0 );
    virtual ~LeitorBackup();

    bool abrirBackup();
    void lerAihs();

    const QList<Aih *> aihs() { return m_aihs; }

signals:
    void erro( QString mensagem );
    void aihsCarregadas();

private:
    QFile *m_arquivoBackup;
    QTextStream *m_backupStream;
    QList<Aih *> m_aihs;

    void inicializarAih( Aih* aih );
};

#endif // BACKUPREADER_H
