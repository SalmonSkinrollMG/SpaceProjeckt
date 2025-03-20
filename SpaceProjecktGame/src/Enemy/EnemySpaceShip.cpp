#include "Enemy/EnemySpaceShip.h"
#include "framework/MathUtility.h"

namespace SPKT
{

	EnemySpaceShip::EnemySpaceShip(World* owningWorld, std::string& texturePath, float collisionDamage, const List<RewardFactoryFunc> rewards)
		:SpaceShip(owningWorld, texturePath),
		mCollisionDamage{ collisionDamage },
		mRewards{rewards}
	{
		SetTeamId(2);
	}

	void EnemySpaceShip::Tick(float deltaTime)
	{
		SpaceShip::Tick(deltaTime);

		if (CheckIfActorOutOfBound(GetActorGlobalBounds().width * 2.0f))
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

	void EnemySpaceShip::AfterBlow()
	{
		SpawnReward();
	}

	void EnemySpaceShip::SpawnReward()
	{
		if (mRewards.size() == 0)
		{
			return;
		}
		int randNum = (int)RandomRange(0, mRewards.size());
		if (randNum >= 0 && randNum < mRewards.size())
		{
			weakPtr<Reward> newReward = mRewards[randNum](GetOwningWorld());
			newReward.lock()->SetActorPosition(GetActorPosition());
		}
	}
}	