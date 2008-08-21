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

#include "wing.h"
#include "plane.h"
#include "world.h"
#include "b2dqt.h"

namespace Flyer
{

// ============================================================================
// Constructor
Wing::Wing ( Plane* pParent, const QString& name ) : Surface ( pParent, name )
{
	_flaps = 0.0;
	_currentFlapsMax = 1.0;
	_currentFlapsMin = 0.0;
}

// ============================================================================
// Destructor
Wing::~Wing()
{
}

// ============================================================================
/// Calculates force [N]
QPointF Wing::calculateForce ( double velocity, double sinAttack ) const
{
	QPointF pos = vec2point( body()->b2body()->GetPosition() );
	
	//double airDensity = parent()->world()->environment()->relativeDensity( pos );
	double airDensity = 1.0;
	
	// lift
	double lift = -airDensity * velocity*velocity * ( _currentLift + _flapsLift*_flaps ) * sinAttack;
	
	// drag (negative, becouse backwards)
	double dragH = _currentDragH + _flapsDrag*_flaps;
	double drag = -airDensity * velocity*velocity * (dragH +( _currentDragV-dragH) * sinAttack*sinAttack );
	
	return QPointF( drag, lift );	
}

// ============================================================================
// Renders wing
void Wing::render( QPainter& painter, const QRectF& rect )
{
	painter.save();
		painter.setTransform( body()->transform(), true );
		painter.setPen( Qt::black );
		
		double wx = cos( ( _inclination*parent()->orientation() ) ) * _width/2;
		double wy = sin( ( _inclination*parent()->orientation() ) ) * _width/2;
		
		double flapsAngle = _inclination + 1.0*_flaps ; // 1 radian. only for rendering
		double fx = cos( ( flapsAngle*parent()->orientation() ) ) * _width/4;
		double fy = sin( ( flapsAngle*parent()->orientation() ) ) * _width/4;
		
		// draw wing
		painter.drawLine( QLineF( -wx/2, -wy/2, wx, wy ) );
		
		// draw flapes
		painter.drawLine( QLineF( -wx/2, -wy/2, -wx/2-fx, -wy/2-fy ) );
		
	painter.restore();
	
	// draw force (DEBUG )
	double fs = 500 ; // force scale
	QPointF wf = aerodynamicForce() / fs;
	const b2Vec2& pos = body()->b2body()->GetPosition();
	
	painter.setPen( Qt::blue );
	painter.drawLine( QLineF( pos.x, pos.y, pos.x + wf.x(), pos.y + wf.y() ) );
		
}

// ============================================================================
// Implements damage
void Wing::damage ( double force )
{
	// TODO
	qDebug("TODO: Implement wing damage");
}

// ============================================================================
/// Sets current flaps value, from range 0-1
void Wing::setFlaps( double f )
{
	if ( f > _currentFlapsMax )
		_flaps = _currentFlapsMax;
	else if ( f < _currentFlapsMin )
		_flaps = _currentFlapsMin;
	else
		_flaps = f;
}

}