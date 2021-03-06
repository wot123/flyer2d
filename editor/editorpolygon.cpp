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

#include <math.h>

#include <QPainter>

#include "editorpoint.h"
#include "b2dqt.h"
#include "common.h"

#include "editorpolygon.h"

// ============================================================================
// Constructor
EditorPolygon::EditorPolygon()
		: EditableItem()
{
}

// ============================================================================
// Destructor
EditorPolygon::~EditorPolygon()
{
}

// ============================================================================
// Returns boundiong rect
QRectF EditorPolygon::boundingRect() const
{
	QRectF polygonRect = polygon().boundingRect();
	double m = ( polygonRect.width() + polygonRect.height() ) * 0.05;
	return QRectF( polygonRect.topLeft() - QPointF( m, m ),
		polygonRect.size() + QSize( m*2, m*2 ) );
}

// ============================================================================
// Paints
void EditorPolygon::paint ( QPainter * painter,
		 const QStyleOptionGraphicsItem * , QWidget *  )
{
	QPolygonF p = polygon();
	painter->setBrush( Qt::NoBrush );
	
	if ( Flyer::isPolygonConvex( p ) )
	{
		if ( isSelected() )
		{
			painter->setPen( Qt::blue );
		}
		else
		{
			painter->setPen( Qt::black );
		}
	}
	else
	{
		painter->setPen( Qt::red );
	}
	
	painter->drawPolygon( p );
}

// ============================================================================
// Gets polygon from editor points
QPolygonF EditorPolygon::polygon() const
{
	QPolygonF p;
	foreach( EditorPoint* pEP, _points )
	{
		p.append( pEP->pos() );
	}
	
	return p;
}

// ============================================================================
// Inits polygon
void EditorPolygon::init( int a_p )
{
	int points = qMin( 8, a_p ); // max 8 points
	
	// remove points
	foreach( EditorPoint* pEP, _points )
	{
		delete pEP;
	}
	_points.clear();
	
	double size = 5; // in meters!
		
	// generate new
	for( int i =0 ;i < points; i++ )
	{
		double angle = i * 2 * M_PI / points;
		
		double x = size*cos(angle);
		double y = size*sin(angle);
		
		EditorPoint* pPoint = new EditorPoint( this );
		pPoint->setPos( x, y );
		_points.append( pPoint );
	}
}

// ============================================================================
// Sets shape from polygon
void EditorPolygon::setPolygon( const QPolygonF& polygon )
{
	// delete all points
	foreach( EditorPoint* p, _points )
	{
		delete p;
	}
	_points.clear();
	
	// create new points
	foreach( QPointF point, polygon )
	{
		EditorPoint* pPoint = new EditorPoint( this );
		pPoint->setPos( point );
		_points.append( pPoint );
	}
	
	update();
}


