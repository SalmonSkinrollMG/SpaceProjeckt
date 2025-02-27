#include "Enemy/Vanguard.h"
#include "weapon/BulletShooter.h"

namespace SPKT {
	Vanguard::Vanguard(World* owningWorld, std::string texturePath , Vector2D velocity)
		:EnemySpaceShip(owningWorld , texturePath),
		mBulletShooter{new BulletShooter(this)}
	{
		SetVelocity(velocity);
		SetActorRotation(180.0f);
	}
	void Vanguard::Tick(float deltaTime)
	{
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
	}

	void Vanguard::Shoot()
	{
		EnemySpaceShip::Shoot();
		mBulletShooter->Shoot();
	}
}