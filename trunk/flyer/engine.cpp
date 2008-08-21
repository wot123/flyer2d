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

#include <QPainter>

#include "Box2D.h"

#include "engine.h"
#include "body.h"
#include "plane.h"
#include "world.h"

namespace Flyer
{

// ============================================================================
// Constructor
Engine::Engine ( Plane* pParent, const QString& name, double thrust, const QPointF& normal /* = QPointF( 1.0, 0.0 )*/ )
	 : System ( pParent, name )
{
	setMaxThrust( thrust );
	_throttle	= 0.0;
	_normal		= normal;
	_propellerBladeLength = 0;
}

// ============================================================================
// Destructor
Engine::~Engine()
{
}

// ============================================================================
// / Sest engine max thrust.
void Engine::setMaxThrust( double thrust )
{
	_maxThrust	= thrust;
	_currentMaxThrust = thrust;
}

// ============================================================================
// Sets throttle
void Engine::setThrottle( double t )
{
	if ( t < 0 )
		_throttle = 0.0;
	else if ( t > 1.0 )
		_throttle = 1.0;
	else 
		_throttle = t;
}


// ============================================================================
// Applies damage
void Engine::damage ( double force )
{
	// currently only damag is reducing max thrust
	_currentMaxThrust -=  _maxThrust * (force / damageCapacity() );
	
	if( _currentMaxThrust < 0.0 )
	{
		_currentMaxThrust = 0.0;
	}
	else
	{
		qDebug("Engine: max thrust reduced to %g", _currentMaxThrust );
	}
}

// ============================================================================
// Simulates engine operation.
void Engine::simulate ( double dt )
{
	Q_ASSERT( body() );
	
	const b2Vec2& pos = body()->b2body()->GetPosition();
	
	QPointF thrust	= thrustForce();
	body()->b2body()->ApplyForce
		( 10.0 * b2Vec2( thrust.x(), thrust.y() ) // newtons per kg
		, pos );
}

// ============================================================================
// Thrust force (in kg)
QPointF Engine::thrustForce()
{
	double angle = body()->b2body()->GetAngle();
	b2Vec2 pos = body()->b2body()->GetPosition();
	double thrust = _throttle * _currentMaxThrust;
	double airDensity = parent()->world()->environment()->relativeDensity( QPointF( pos.x, pos.y ) );
	
	// thrust along the normal vector
	QTransform t;
	t.rotateRadians( angle ); 
	
	return t.map( _normal*thrust*airDensity );
}

// ============================================================================
// Renders
void Engine::render( QPainter& painter, const QRectF& rect )
{
	Q_ASSERT( body() );
	
	// render body
	body()->render( painter );

	// render propeller
	painter.save();
		painter.setTransform( body()->transform(), true );
		renderPropeller( painter );
	painter.restore();

	// render force (debug )
	double fs = 50 ; // force scale
	QPointF tf = thrustForce() / fs;
	const b2Vec2& pos = body()->b2body()->GetPosition();

	painter.setPen( Qt::red );
	painter.drawLine( QLineF( pos.x, pos.y, pos.x + tf.x(), pos.y + tf.y() ) );
	
}


// ============================================================================
/// Renders propeller. Assumes that painter is transformed to engine body cooridnates
void Engine::renderPropeller( QPainter& painter )
{
	// axis
	if ( ! _propellerAxis.isNull() )
	{
		painter.setPen( Qt::black );
		painter.drawLine( _propellerAxis );
	}
	
	// rotating blades
	if ( _propellerBladeLength > 0 && ! _propellerCenter.isNull() )
	{
		QPointF bladeVector = QPointF( - _normal.y(), _normal.x() ) * _propellerBladeLength;
		painter.setPen( QColor( 0, 0, 0, 128 ) );
		painter.drawLine( QLineF( _propellerCenter - bladeVector, _propellerCenter + bladeVector ) );
	}
}


}
