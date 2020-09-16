#include "Poo.h"
#include "Graphics.h"
#include <assert.h>


void Poo::Init(const Vec2D& pos, const Vec2D& vel)
{
	assert( initialized == false );
	pos_vect = pos;	
	vel_vect = vel;
	initialized = true;
}

void Poo::Update( float dt )
{
	assert( initialized == true );
	pos_vect += vel_vect * dt;	

	const float right = pos_vect.x + width;
	if(pos_vect.x < 0 )
	{
		pos_vect.x = 0;
		vel_vect.x = -vel_vect.x;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		pos_vect.x = float( Graphics::ScreenWidth - 1 ) - width;
		vel_vect.x = -vel_vect.x;
	}

	const float bottom = pos_vect.y + height;
	if(pos_vect.y < 0 )
	{
		pos_vect.y = 0;
		vel_vect.y = -vel_vect.y;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		pos_vect.y = float( Graphics::ScreenHeight - 1 ) - height;
		vel_vect.y = -vel_vect.y;
	}
}

bool Poo::TestCollision( const Dude& dude ) const
{
	assert( initialized == true );
	const float duderight = dude.get_pos().x + dude.GetWidth();
	const float dudebottom = dude.get_pos().y + dude.GetHeight();
	const float pooright = pos_vect.x + width;
	const float poobottom = pos_vect.y + height;

	return
		duderight >= pos_vect.x &&
		dude.get_pos().x <= pooright &&
		dudebottom >= pos_vect.y &&
		dude.get_pos().y <= poobottom;
}

void Poo::Draw( Graphics& gfx ) const
{
	assert( initialized == true );

	const int x_int = int(pos_vect.x );
	const int y_int = int(pos_vect.y );

	gfx.PutPixel( 14 + x_int,0 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,3 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,9 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,10 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,12 + y_int,111,62,0 );
	gfx.PutPixel( 13 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 14 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 15 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 16 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,13 + y_int,109,61,0 );
	gfx.PutPixel( 11 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,15 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,16 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,16 + y_int,109,61,0 );
	gfx.PutPixel( 14 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,16 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 2 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 3 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 4 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 5 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,17 + y_int,43,24,0 );
	gfx.PutPixel( 8 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,17 + y_int,40,22,0 );
	gfx.PutPixel( 14 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,17 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,18 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,19 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,19 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,20 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,20 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 2 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 3 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 4 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 5 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 6 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,23 + y_int,51,28,0 );
}