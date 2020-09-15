#pragma once

class Vec2D
{
public:
	Vec2D() = default;
	Vec2D(float in_x, float in_y);
	Vec2D operator+(const Vec2D& v2) const; // vektor trenutnega objekta + vektor v2 => nov vektor Vec2D
	Vec2D& operator+=(const Vec2D& v2); // pri dodelitvenih operatorjih uporabljamo referenco na vrnjen objekt
												//zaradi moznosti verizenja
	Vec2D operator*(float f) const;
	Vec2D& operator*=(float f);
public:	
	float x;
	float y;
};

