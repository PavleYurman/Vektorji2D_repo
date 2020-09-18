#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2D.h"
#include "MainWindow.h"

class Dude
{
public:	
	void ClampToScreen();
	void Draw( Graphics& gfx ) const;
	void Update( const MainWindow& wnd,float dt );
	Vec2D get_pos() const;	
	float GetWidth() const;
	float GetHeight() const;
private:
	Vec2D pos_vec = Vec2D(400.0f, 300.0f);
	Vec2D vel_vec = Vec2D(1.0f * 60.0f, 1.0f * 60.0f);
	/*static constexpr float speed = 1.0f * 60.0f;*/
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};