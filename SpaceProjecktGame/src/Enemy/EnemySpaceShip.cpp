#include "Enemy/EnemySpaceShip.h"

namespace SPKT
{
	EnemySpaceShip::EnemySpaceShip(World* owningWorld, std::string& texturePath , float collisionDamage)
		:SpaceShip(owningWorld , texturePath),
		mCollisionDamage{collisionDamage}
	{
		SetTeamId(2);
	}

	void EnemySpaceShip::Tick(float deltaTime)
	{
		SpaceShip::Tick(deltaTime);

		if (CheckIfActorOutOfBound(GetActorGlobalBounds().width))
		{
			Destroy();
		}
	}

	void EnemySpaceShip::OnActorOverlap(Actor* otherActor)
	{
		SpaceShip::OnActorOverlap(otherActor);
		if (IsOtherHostile(otherActor))
		{
			otherActor->ApplyDamage(mCollisionDamage);
		}
	}

	void EnemySpaceShip::OnActorEndOverlap(Actor* otherActor)
	{
		SpaceShip::OnActorEndOverlap(otherActor);
	}
}	