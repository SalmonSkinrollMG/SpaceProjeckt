#pragma once
#include "spaceShip/SpaceShip.h"
#include "player/Reward.h"

namespace SPKT
{
	class EnemySpaceShip : public SpaceShip
	{
	public:
		EnemySpaceShip(World* owningWorld , std::string& texturePath , float collisionDamage = 200.0f ,
			const List<RewardFactoryFunc> rewards = {CreateHealthReward, CreateFrontalWiperReward,CreateThreeWayShooterReward});
		virtual void Tick(float deltaTime);
	private:
		float mCollisionDamage;		

		virtual void OnActorOverlap(Actor* otherActor) override;
		virtual void OnActorEndOverlap(Actor* otherActor) override;

		virtual void AfterBlow() override;

		List<RewardFactoryFunc> mRewards;
		void SpawnReward();
	};
}