#include "weapon/BulletShooter.h"
#include "weapon/Bullet.h"
#include "framework/World.h"

namespace SPKT
{

	BulletShooter::BulletShooter(Actor* owner, float shootingInterval, Vector2D& positonOffset, float rotationOffset)
		:WeaponBase(owner)
		, mShootingClock{}
		, mShootingInterval{shootingInterval}
		, mLocalPositionOffset{positonOffset}
		, mLocalRotationOffset{rotationOffset}
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
		Vector2D ownerForward = GetOwner()->GetActorForwardVector();
		Vector2D ownerRight = GetOwner()->GetActorRightVector();


		mShootingClock.restart();

		weakPtr<Bullet> newBullet = GetOwner()->GetOwningWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		newBullet.lock()->SetActorPosition(GetOwner()->GetActorPosition() + ownerForward * mLocalPositionOffset.x + ownerRight * mLocalPositionOffset.y);
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation() + mLocalRotationOffset);
		
	}
}