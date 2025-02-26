#pragma once
#include"framework/Core.h"

namespace SPKT {


		Vector2D RotationToVector(float rotation);

		float DegreesToRadians(float degrees);

		float RadiansToDegrees(float radians);

		float LerpFloat(float a, float b, float alpha);

		float RandomRange(float min, float max);

		Vector2D RandomUnitVector();

		sf::Color LerpColor(const sf::Color& a, const sf::Color& b, float alpha);

		Vector2D LerpVector(const Vector2D& a, const Vector2D& b, float alpha);

		template <typename T>
		float GetVectorLength(const sf::Vector2<T>& vector)
		{
			return std::sqrt(vector.x * vector.x + vector.y * vector.y); //pythgoros theorem
		}

		template <typename T>
		sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vector, float scaleAmount)
		{
			vector.x *= scaleAmount;
			vector.y *= scaleAmount;

			return vector;
		}
		/*
		* clam the vector within its vector length.
		*/
		template <typename T>
		sf::Vector2<T>& Normalize(sf::Vector2<T>& vector)
		{
			float vectorLength = GetVectorLength(vector);
			if (vectorLength == 0.0f)
			{
				return sf::Vector2<T>{};
			}
			ScaleVector(vector, 1.0 / vectorLength);
			return vector;
		}
}