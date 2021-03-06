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

#ifndef FLYERMAINWINDOW_H
#define FLYERMAINWINDOW_H

#include <QWidget>

#include "ui_mainwindow.h"

namespace Flyer
{
class StatusWindow;

/**
	@author Maciek Gajewski <maciej.gajewski0@gmail.com>
*/
class MainWindow : public QWidget, private Ui::MainWindow
{
Q_OBJECT
public:
	MainWindow( QWidget* parent = 0, Qt::WindowFlags f = 0);
	virtual ~MainWindow();
	
protected:

private slots:

	virtual void closeEvent( QCloseEvent* );

private:

	StatusWindow* _pStatusWindow;
};

}

#endif // FLYERMAINWINDOW_H

// EOF


