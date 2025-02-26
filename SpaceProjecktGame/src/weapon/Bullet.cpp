#include "weapon/Bullet.h"

namespace SPKT
{
	Bullet::Bullet(World* owningWorld, Actor* owningActor, std::string texturePath, float bulletDamage, float bulletSpeed)
		:Actor(owningWorld , texturePath)
		,mOwner{owningActor}
		,mBulletDamage{bulletDamage}
		,mBulletSpeed{bulletSpeed}
	{
		SetTeamId(owningActor->GetTeamId());
	}

	void Bullet::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		Move(deltaTime);
		if (CheckIfActorOutOfBound())
		{
			Destroy();
		}
	}

	void Bullet::BeginPlay()
	{
		Actor::BeginPlay();
		SetPhysicsEnabled(true);
	}

	void Bullet::OnActorOverlap(Actor* other)
	{
		Actor::OnActorOverlap(other);
		if (IsOtherHostile(other))
		{
			other->ApplyDamage(GetDamage());
			Destroy();
		}
	}

	void Bullet::Move(float deltaTime)
	{
		AddActorPositionOffset(GetActorForwardVector() * GetBulletSpeed() * deltaTime);
	}

}