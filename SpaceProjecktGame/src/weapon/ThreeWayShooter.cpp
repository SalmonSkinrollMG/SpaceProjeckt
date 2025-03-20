#include "weapon/ThreeWayShooter.h"

namespace SPKT
{
	ThreeWayShooter::ThreeWayShooter(Actor* owner, float cooldownTime, Vector2D& localOffset)
		:WeaponBase{ owner },
		mShooterLeft{ new BulletShooter{owner , cooldownTime , localOffset + Vector2D{10.0f , -10.0f} ,-30.0f}},
		mShooterRight{ new BulletShooter{owner , cooldownTime , localOffset } },
		mShooterMiddle{ new BulletShooter{owner , cooldownTime , localOffset + Vector2D{10.0f , 10.0f} ,30.0f}},
		mTopLevelShooterLeft{ new BulletShooter{owner , cooldownTime , localOffset + Vector2D{10.0f , -10.0f}, -15.0f}},
		mTopLevelShooterRight{ new BulletShooter{owner , cooldownTime , localOffset + Vector2D{10.0f , 10.0f}, 15.0f}}
	{
		mShooterLeft->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mShooterRight->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mShooterMiddle->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mTopLevelShooterLeft->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mTopLevelShooterRight->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
	}

	void ThreeWayShooter::IncrementLevel(int amt)
	{
		WeaponBase::IncrementLevel(amt);
		mShooterLeft->IncrementLevel(amt);
		mShooterRight->IncrementLevel(amt);
		mShooterMiddle->IncrementLevel(amt);
		mTopLevelShooterLeft->IncrementLevel(amt);
		mTopLevelShooterRight->IncrementLevel(amt);
	}

	void ThreeWayShooter::ShootImpl()
	{
		mShooterLeft->Shoot();
		mShooterRight->Shoot();
		mShooterMiddle->Shoot();

		if (GetCurrentLevel() == GetMaxLevl())
		{
			mTopLevelShooterLeft->Shoot();
			mTopLevelShooterRight->Shoot();
		}
	}

}