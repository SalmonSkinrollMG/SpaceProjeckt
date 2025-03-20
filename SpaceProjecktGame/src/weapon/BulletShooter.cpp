#include "weapon/BulletShooter.h"
#include "weapon/Bullet.h"
#include "framework/World.h"

namespace SPKT
{


	BulletShooter::BulletShooter(Actor* owner, float shootingInterval, Vector2D& positonOffset, float rotationOffset, const std::string& bulletTexturePath)
		:WeaponBase(owner)
		, mShootingClock{}
		, mShootingInterval{ shootingInterval }
		, mLocalPositionOffset{ positonOffset }
		, mLocalRotationOffset{ rotationOffset }

	{
		SetBulletTexturePath(bulletTexturePath);
	}

	bool SPKT::BulletShooter::IsInCooldown() const
	{
		if (mShootingClock.getElapsedTime().asSeconds() > mShootingInterval/GetCurrentLevel())
		{
			return false;
		}
		return true;
	}

	void BulletShooter::IncrementLevel(int amt)
	{
		WeaponBase::IncrementLevel(amt);
		mShootingInterval /= GetCurrentLevel();
	}

	void BulletShooter::ShootImpl()
	{
		Vector2D ownerForward = GetOwner()->GetActorForwardVector();
		Vector2D ownerRight = GetOwner()->GetActorRightVector();


		mShootingClock.restart();

		weakPtr<Bullet> newBullet = GetOwner()->GetOwningWorld()->SpawnActor<Bullet>(GetOwner(), mBulletTexturePath);
		newBullet.lock()->SetActorPosition(GetOwner()->GetActorPosition() + ownerForward * mLocalPositionOffset.x + ownerRight * mLocalPositionOffset.y);
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation() + mLocalRotationOffset);
		
	}
}