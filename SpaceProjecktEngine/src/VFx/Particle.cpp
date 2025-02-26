#include "VFx/Particle.h"
#include "framework/MathUtility.h"

namespace SPKT
{
	Particle::Particle(World* owningWorld, std::string& texturePath)
		:Actor{ owningWorld , texturePath }, mVelocity{ 0.0f ,0.0f }, mLifeTime{ 1.0f },mTimer{}
	{

	}

	void Particle::Tick(float DeltaTime)
	{
		Actor::Tick(DeltaTime);

		Move(DeltaTime);
		Fade(DeltaTime);

		if (mTimer.getElapsedTime().asSeconds() >= mLifeTime)
		{
			Destroy();
		}
	}

	void Particle::RandomVelocity(float minSpeed, float maxSpeed)
	{
		mVelocity = RandomUnitVector() * RandomRange(minSpeed, maxSpeed);
	}

	void Particle::RandomSize(float minSize, float maxSize)
	{
		float randomScale = RandomRange(minSize, maxSize);
		GetActorSprite().setScale(randomScale , randomScale);
	}

	void Particle::RandomLifeTime(float minTime, float maxTime)
	{
		mLifeTime = RandomRange(minTime , maxTime);
	}

	void Particle::Move(float DeltaTime)
	{
		AddActorPositionOffset(mVelocity * DeltaTime);
	}

	void Particle::Fade(float DeltaTime)
	{
		float elapsedTime = mTimer.getElapsedTime().asSeconds();
		//sf::Color(255 , 255 ,255 ,0) is basically ment transparent.
		GetActorSprite().setColor(LerpColor(GetActorSprite().getColor(),sf::Color(255 , 255 ,255 ,0), elapsedTime/mLifeTime));
		GetActorSprite().setScale( LerpVector(GetActorSprite().getScale(), Vector2D(0.0f, 0.0f), elapsedTime / mLifeTime));
	}
}