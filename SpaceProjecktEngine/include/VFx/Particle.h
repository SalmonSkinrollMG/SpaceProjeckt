#pragma once 
#include "framework/Actor.h"

namespace SPKT
{
	class Particle : public Actor
	{
	public:
		Particle(World* owningWorld, std::string& texturePath);
		virtual void Tick(float DeltaTime) override;

		void RandomVelocity(float minSpeed, float maxSpeed);
		void RandomSize(float minSize , float maxSize);
		void RandomLifeTime(float minTime, float maxTime);

	private:

		void Move(float DeltaTime);
		void Fade(float DeltaTime);

		Vector2D mVelocity;
		float mLifeTime;
		sf::Clock mTimer;

	};
}