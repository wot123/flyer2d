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

#include <sys/time.h>

#include <QPainter>
#include <QPaintEngine>

#include "common.h"

namespace Flyer
{

// ============================================================================
/// Returns current time in ms.
double getms()
{
	struct timeval tv;
	gettimeofday( &tv, 0 );
	
	return (tv.tv_sec & 0xff ) * 1e3 + tv.tv_usec * 1e-3;
}

// ============================================================================
/// Checks if painter paints on OpenGL surface.
bool isOpenGL( QPainter* p )
{
	return p->paintEngine()->type() == QPaintEngine::OpenGL;
}

}

// EOF
