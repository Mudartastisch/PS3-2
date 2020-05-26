#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition

struct Vec2
{
    float x;
    float y;
    Vec2(float i = 0.0f, float j = 0.0f):x(i), y(j) {}
    Vec2(Vec2& temp) {
		x = temp.x;
		y = temp.y;
	};

    Vec2& operator+=( Vec2 const& v );
    Vec2& operator-=( Vec2 const& v );
    Vec2& operator*=( float s );
    Vec2& operator/=( float s ); 
};     

# endif // VEC2_HPP