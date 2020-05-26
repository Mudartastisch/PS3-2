#include "vec2.hpp"
#include <iostream>

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2 & Vec2::operator*=(float s)
{
	x = x*s;
	y = y*s;
	return *this;
}

Vec2 & Vec2::operator/=(float s)
{
	if (s == 0) {
		std::cerr << "You can't devide by ZERO!" << "\n";
		return *this;
	}
	x = x/s;
	y = y/s;
	return *this;
}