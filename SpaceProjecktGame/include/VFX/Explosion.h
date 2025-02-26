#pragma once
#include "framework/World.h"
#include "framework/Core.h"

namespace SPKT
{
	class World;
	class Explosion
	{
	public:
		Explosion(int particleAmt =20 ,
			float maxSize = 1.0f, float minSize = 0.5f,
			float maxLifeTime = 5.0f, float minLifeTime = 3.0f,
			float maxSpeed = 200, float minSpeed = 100,
			const sf::Color& color = sf::Color(255,111,0,255),
			const List<std::string> texturePaths =	{
												"SpaceShooterRedux/PNG/Effects/star1.png",
												"SpaceShooterRedux/PNG/Effects/star2.png",
												"SpaceShooterRedux/PNG/Effects/star3.png"
												}
			);

		void SpawnExplosion(World* world, Vector2D position);

	private:
		int mParticleAmount;

		float mMaxSize;
		float mMinSize;

		float mMaxLifeTime;
		float mMinLifeTime;

		float mMaxSpeed;
		float mMinSpeed;

		const sf::Color& mParticleColor;

		const List<std::string> mTexturePaths;
		;

	};
}