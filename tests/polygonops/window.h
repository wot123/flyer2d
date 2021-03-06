// Copyright (C) 2008 Maciej Gajewski <maciej.gajewski0@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QList>
#include <QPolygonF>
#include "ui_window.h"

/**
 @author Maciek Gajewski <maciej.gajewski0@gmail.com>
*/

class Window : public QWidget, public Ui::Window
{
	Q_OBJECT

public:
	Window( QWidget *parent = 0 );
	virtual ~Window();
	
protected:

	virtual void paintEvent( QPaintEvent* e );
	
private slots:

	void on_buttonLoad_clicked();
	void on_buttonSplit_clicked();
	void on_buttonTriangulate_clicked();

private:

	QList<QPolygonF> _polygons;
	QList<QLineF> _lines;

};

#endif // WINDOW_H

// EOF


