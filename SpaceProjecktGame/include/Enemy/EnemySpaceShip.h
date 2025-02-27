#pragma once
#include "spaceShip/SpaceShip.h"

namespace SPKT
{
	class EnemySpaceShip : public SpaceShip
	{
	public:
		EnemySpaceShip(World* owningWorld , std::string& texturePath , float collisionDamage = 200.0f);
		virtual void Tick(float deltaTime);
	private:
		float mCollisionDamage;		

		virtual void OnActorOverlap(Actor* otherActor) override;
		virtual void OnActorEndOverlap(Actor* otherActor) override;


	};
}