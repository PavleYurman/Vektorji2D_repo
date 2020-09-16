#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2D.h"

class Poo
{
public:
	void Init(const Vec2D& pos, const Vec2D& vel);
	void Update( float dt );
	bool TestCollision( const Dude& dude ) const;
	void Draw( Graphics& gfx ) const;
private:
	Vec2D pos_vect;
	Vec2D vel_vect;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool initialized = false;
};