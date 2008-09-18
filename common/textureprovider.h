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

#ifndef FLYERTEXTUREPROVIDER_H
#define FLYERTEXTUREPROVIDER_H

#include "texture.h"

#include <QImage>

namespace Flyer
{

/**
TextureProvider is a utility which provides textures for rendering. Textures are identified
as file names (relative path). The provider knows where to look for them.
@author Maciek Gajewski <maciej.gajewski0@gmail.com>
*/

class TextureProvider
{
public:

	/// Loads named texture from texture library
	static Texture loadTexture( const QString& texture );
	
	/// Returns disk path (may be resource path) to texture library.
	static QString libraryPath();
	
};

}

#endif // FLYERTEXTUREPROVIDER_H

// EOF


