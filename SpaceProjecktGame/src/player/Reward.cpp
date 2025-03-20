#include "player/Reward.h"
#include "player/Player.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"
#include "framework/World.h"

namespace SPKT 
{
	Reward::Reward(World* owningWorld, const std::string& texturePath, RewardFunc rewardFunc, float speed)
		:Actor{owningWorld , texturePath},
		mSpeed{ speed },
		mRewardFunc{rewardFunc}
	{
	}

	void Reward::BeginPlay()
	{
		Actor::BeginPlay();
		SetPhysicsEnabled(true);
	}

	void Reward::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorPositionOffset({ 0.0f, mSpeed * deltaTime });
	}

	void Reward::OnActorOverlap(Actor* otherActor)
	{
		//TODO : Find BetterWays to do this.
		Player* playerSpaceShip = static_cast<Player*>(otherActor);
		if (playerSpaceShip != nullptr && !playerSpaceShip->IsPendingDestroy())
		{
			mRewardFunc(playerSpaceShip);
		}
	}

	weakPtr<Reward> CreateHealthReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/pill_green.png" , RewardHelath);
	}

	weakPtr<Reward> CreateThreeWayShooterReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/powerupRed_bolt.png", RewardThreeWasyShooer);
	}

	weakPtr<Reward> CreateFrontalWiperReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/Power-ups/powerupGreen_bolt.png", RewardFrontalWiper);
	}

	weakPtr<Reward> CreateReward(World* world, const std::string& texturePath, RewardFunc rewardFunc)
	{
		weakPtr<Reward> reward = world->SpawnActor<Reward>(texturePath , rewardFunc);
		return reward;
	}

	void RewardHelath(Player* player)
	{
		static float rewardAmt = 10.0f;
		if (player && !player->IsPendingDestroy())
		{
			player->GetHealthComponent().SetHealth(rewardAmt);
		}
	}

	void RewardThreeWasyShooer(Player* player)
	{
		if (player && !player->IsPendingDestroy())
		{
			player->SetWeapon(uniquePtr<WeaponBase>{new ThreeWayShooter{ player, 0.4f, Vector2D{50.0f,0.0f} }});
		}
	}

	void RewardFrontalWiper(Player* player)
	{
		if (player && !player->IsPendingDestroy())
		{
			player->SetWeapon(uniquePtr<WeaponBase>{new FrontalWiper{ player, 0.4f, Vector2D{50.0f,0.0f} }});
		}
	}
}