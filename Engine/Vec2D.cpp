#include "Vec2D.h"

Vec2D::Vec2D(float in_x, float in_y)
	:
	x(in_x),
	y(in_y)
{
}

Vec2D Vec2D::operator+(const Vec2D& v2) const // lev obj.(osnovni) + desni obj.
{	
	return Vec2D( x + v2.x, y + v2.y );
}

Vec2D& Vec2D::operator+=(const Vec2D& v2) // ni const, saj se objekt na levi(osnovni) spreminja
{
	// option 0:	
	//x += v2.x;
	//y += v2.y;
	//return *this; 

	// option 1:
	//*this = *this + v2;// *this pomeni klic tega objekta nad katerim se klice operator+=(osnovni oz. levi operand v operatorju+=)
	//return *this;

	// option 2:
	return *this = *this + v2; // --> saj,operator dodelitve vrne referenco na samosesklicujoci objekt
}

Vec2D Vec2D::operator*(float f) const
{
	return Vec2D(x * f, y * f);
}

Vec2D& Vec2D::operator*=(float f)
{
	return *this = *this * f;
}
