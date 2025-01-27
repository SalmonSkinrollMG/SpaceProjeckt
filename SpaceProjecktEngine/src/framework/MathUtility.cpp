#pragma once
#include "framework/MathUtility.h"

namespace SPKT
{
	const float PI = 3.145926535;

	Vector2D RotationToVector(float rotation)
	{
		float radian = DegreesToRadians(rotation);
		return Vector2D(std::cos(radian) , std::sin(radian));
	}
	float DegreesToRadians(float degrees)
	{
		return degrees * (PI/180.f);
	}
	float RadiansToDegrees(float radians)
	{
		return radians + (180.0f/PI);
	}
}