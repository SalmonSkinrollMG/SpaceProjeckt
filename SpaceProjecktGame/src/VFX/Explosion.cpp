#include "VFX/Explosion.h"
#include "framework/MathUtility.h"
#include "VFx/Particle.h"
#include "framework/World.h"

namespace SPKT
{
	Explosion::Explosion(int particleAmt,
		float maxSize, float minSize,
		float maxLifeTime, float minLifeTime,
		float maxSpeed, float minSpeed,
		const sf::Color& color,
		const List<std::string> texturePaths)
		: mParticleAmount{particleAmt},
		mMaxSize{maxSize} , mMinSize{minSize},
		mMaxLifeTime{maxLifeTime} , mMinLifeTime{minLifeTime},
		mMaxSpeed{maxSpeed} , mMinSpeed{minSpeed},
		mParticleColor{color},
		mTexturePaths{texturePaths}
	{
	}

	void Explosion::SpawnExplosion(World* world , Vector2D position)
	{
		for (int i = 0; i < mParticleAmount; i++)
		{
			std::string texturePath = mTexturePaths[(int)RandomRange(0, mTexturePaths.size())];
			weakPtr<Particle> particle = world->SpawnActor<Particle>(texturePath);

			particle.lock()->RandomLifeTime(mMinLifeTime , mMaxLifeTime);
			particle.lock()->SetActorPosition(position);
			particle.lock()->RandomSize(mMinSize , mMaxSize);
			particle.lock()->RandomVelocity(mMinSpeed, mMaxSpeed);
			particle.lock()->GetActorSprite().setColor(mParticleColor);
		}
	}


}