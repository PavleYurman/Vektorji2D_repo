#include "Vec2D.h"
#include <cmath>

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

Vec2D Vec2D::operator-(const Vec2D& v2) const
{
	return Vec2D( x - v2.x, y - v2.y );
}

Vec2D& Vec2D::operator-=(const Vec2D& v2)
{
	return *this = *this - v2;
}

float Vec2D::GetLengthSq() const
{
	return x * x + y * y;
}

float Vec2D::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

Vec2D& Vec2D::Normalize()
{
	//return *this = GetNormalize(); // vrne normalizirano vrednost tega vektorja in nadomesti njegovo vrednost - vrne normaliziran vektor
	return *this = GetNormalize();
}

Vec2D Vec2D::GetNormalize() const
{
	//return Vec2D(x * (1 / GetLength()), y * (1 / GetLength())); // vrne samo normalizirano vrednost tega vektorja
	const float length = GetLength();
	if(length != 0.0f)
	{
		return *this * length;		
	}
	//return Vec2D(0.0f, 0.0f); ali
	return *this;
}




