#include "weapon/Bullet.h"

namespace SPKT
{
	Bullet::Bullet(World* owningWorld, Actor* owningActor, std::string texturePath, float bulletDamage, float bulletSpeed)
		:Actor(owningWorld , texturePath)
		,mOwner{owningActor}
		,mBulletDamage{bulletDamage}
		,mBulletSpeed{bulletSpeed}
	{
	}
	void Bullet::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		Move(deltaTime);
	}

	void Bullet::Move(float deltaTime)
	{
		AddActorPositionOffset(GetActorForwardVector() * GetBulletSpeed() * deltaTime);
	}

}