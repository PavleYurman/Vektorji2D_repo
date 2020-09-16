#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2D.h"

class Goal
{
public:
	Goal( const Vec2D& pos)
		:
		pos_vect(pos)
	{}
	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( int(pos_vect.x),int(pos_vect.y),int( dimension ),int( dimension ),c );
	}
	bool TestCollision( const Dude& dude ) const
	{
		const float duderight = dude.get_pos().x + dude.GetWidth();
		const float dudebottom = dude.get_pos().y + dude.GetHeight();
		const float pooright = pos_vect.x + dimension;
		const float poobottom = pos_vect.y + dimension;

		return
			duderight >= pos_vect.x &&
			dude.get_pos().x <= pooright &&
			dudebottom >= pos_vect.y &&
			dude.get_pos().y <= poobottom;
	}
	void Respawn( const Vec2D& new_pos )
	{
		pos_vect = new_pos;
	}
	void UpdateColor()
	{
		if( colorIncreasing )
		{
			if( c.GetR() >= 253 )
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color( c.GetR() + 2,c.GetG() + 4,c.GetB() + 4 );
			}
		}
		else
		{
			if( c.GetR() <= 127 )
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color( c.GetR() - 2,c.GetG() - 4,c.GetB() - 4 );
			}
		}
	}
private:
	static constexpr float dimension = 20;
	Color c = { 127,0,0 };
	bool colorIncreasing = true;
	Vec2D pos_vect;
};