#pragma once
#include "framework/MathUtility.h"
#include <random>

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

	float LerpFloat(float a, float b, float alpha)
	{
		if (alpha < 0) alpha = 0;
		if (alpha > 1) alpha = 1;

		return a + (b - a) * alpha;
	}

	float RandomRange(float min, float max)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_real_distribution<float> distribution{ min , max };

		return distribution(gen);
	}

	Vector2D RandomUnitVector()
	{
		float RandX = RandomRange(-1, 1);
		float RandY = RandomRange(-1 ,1);
		Vector2D RandomVector{ RandX , RandY };

		Normalize(RandomVector);

		return RandomVector;
	}

	sf::Color LerpColor(const sf::Color& a, const sf::Color& b, float alpha)
	{
		int lerpR = LerpFloat(a.r, b.r, alpha);
		int lerpG = LerpFloat(a.g, b.g, alpha);
		int lerpB = LerpFloat(a.b, b.b, alpha);
		int lerpA = LerpFloat(a.a, b.a, alpha);

		return sf::Color(lerpR , lerpG , lerpB , lerpA);
	}

	Vector2D LerpVector(const Vector2D& a, const Vector2D& b, float alpha)
	{
		float lerpX = LerpFloat(a.x, b.x, alpha);
		float lerpY = LerpFloat(a.y, b.y, alpha);

		return Vector2D(lerpX , lerpY);
	}



}