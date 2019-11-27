#ifndef _MATHHELPER_H
#define _MATHHELPER_H
#include <math.h> 

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f 

struct Vector2 
{
	float x;
	float y;
	float radius;

	Vector2(float _x = 0.0f, float _y = 0.0f, float _r=0.0f) : x(_x), y(_y), radius(_r) {}

	float MagnitudeSqr() //Returning the magnitude (lenght) of our vector squared 
	{
		return x * x + y * y;
	}

	float Magnitude() //Returning the magnitude (lenght) of our vector squareroot, aka the hypotenuse 
	{
		return (float)sqrtf(x * x + y * y); //Pythagorean theorem
	}

	float Circumference(float radius) 
	{
		return(float)((radius * 2) * PI);
	}

	Vector2 Normalized() //Normalizing a vector, if it has X lenght we make it to 1 in lenght, BASICALLY GETTING RID OF THE MAGNITUDE but keeps the direction, why? I don't know!
	{
		float mag = Magnitude();

		return Vector2(x / mag, y / mag);
	}
};

inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs) //Adding vectors
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y); //lhs = left hand side, rhs = right hand side
}

inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs) //Subtracting vectors
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator *(const Vector2& lhs, const Vector2& rhs) //Subtracting vectors
{
	return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline Vector2 operator *(const float& lhs, const Vector2& rhs) //Subtracting vectors
{
	return Vector2(lhs * rhs.x, lhs * rhs.y);
}
inline Vector2 operator /(const Vector2& lhs, const Vector2& rhs) //Subtracting vectors
{
	return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
}

Vector2 RotateVector(Vector2& vec, float angle) {
	float radAngle = (float)(angle * DEG_TO_RAD);

	return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}

inline Vector2 Lerp(Vector2& start, Vector2& end, float time) {
	if (time <=0.0f)
	{
		return start;
	}

	if (time >= 1.0f)
	{
		return end;
	}

	Vector2 dir = (end - start).Normalized();
	float mag = (end - start).Magnitude();

	return start + dir * mag * time;
}

struct BezierCurve {
	Vector2 p0; //Start point
	Vector2 p1; //Controll point for the start point 
	Vector2 p2; //Controll point for the end point
	Vector2 p3; //End point

	Vector2 CalculateCurvePoint(float t) {
		float tt = t * t;
		float ttt = tt * t;
		float u = 1.f - t;
		float uu = u * u;
		float uuu = uu * u;

		Vector2 point = (uuu * p0) +(3*uu*t*p1)+(3* u *tt * p2)+(ttt*p3);

		point.x = round(point.x);
		point.y = round(point.y);

		return point;
	}
};
#endif