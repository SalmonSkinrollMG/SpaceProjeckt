#include "weapon/BulletShooter.h"
#include "weapon/Bullet.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace SPKT
{

	BulletShooter::BulletShooter(Actor* owner, float shootingInterval)
		:WeaponBase(owner)
		,mShootingClock{}
		,mShootingInterval{ shootingInterval }
	{
	}

	bool SPKT::BulletShooter::IsInCooldown() const
	{
		if (mShootingClock.getElapsedTime().asSeconds() > mShootingInterval)
		{
			return false;
		}
		return true;
	}

	void BulletShooter::ShootImpl()
	{
		mShootingClock.restart();

		weakPtr<Bullet> newBullet = GetOwner()->GetOwningWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		newBullet.lock()->SetActorPosition(GetOwner()->GetActorPosition());
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());
		
	}
}