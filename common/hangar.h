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

#ifndef FLYERHANGAR_H
#define FLYERHANGAR_H

#include "machine.h"

namespace Flyer
{

/**
Hangar is a building repering other machines that comes near him.
@author Maciek Gajewski <maciej.gajewski0@gmail.com>
*/

class Hangar : public Machine
{

public:
	Hangar( World* pWorld, double location );
	virtual ~Hangar();
	
	virtual void timer1();
	
private:

	QRectF	_activeArea;	///< Active area

};

}

#endif // FLYERHANGAR_H

// EOF


