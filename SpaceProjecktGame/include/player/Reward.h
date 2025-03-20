#pragma once
#include "framework/Actor.h"
#include "functional"

namespace SPKT
{
	class Player;
	using RewardFactoryFunc = std::function<weakPtr<Reward>(World*)>;
	using RewardFunc = std::function<void(Player*)>;
	class Reward : public Actor
	{
	public:
		Reward(World* owningWorld , const std::string& texturePath ,RewardFunc rewardFunc, float speed = 200.0f);
		virtual void BeginPlay() override;
		virtual void Tick(float deltaTime)override;

	private:
		virtual void OnActorOverlap(Actor* otherActor)override;
		float mSpeed;
		RewardFunc mRewardFunc;
	};

	weakPtr<Reward> CreateHealthReward(World* world);
	weakPtr<Reward> CreateThreeWayShooterReward(World* world);
	weakPtr<Reward> CreateFrontalWiperReward(World* world);


	weakPtr<Reward> CreateReward(World* world , const std::string& texturePath , RewardFunc rewardFunc);

	void RewardHelath(Player* player);
	void RewardThreeWasyShooer(Player* player);
	void RewardFrontalWiper(Player* player);
}