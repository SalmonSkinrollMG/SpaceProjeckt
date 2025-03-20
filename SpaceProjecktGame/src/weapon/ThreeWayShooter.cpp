#include "weapon/ThreeWayShooter.h"

namespace SPKT
{
	ThreeWayShooter::ThreeWayShooter(Actor* owner, float cooldownTime, Vector2D& localOffset)
		:WeaponBase{ owner },
		mShooterLeft{ new BulletShooter{owner , cooldownTime , localOffset ,-30.0f}},
		mShooterRight{ new BulletShooter{owner , cooldownTime , localOffset } },
		mShooterMiddle{ new BulletShooter{owner , cooldownTime , localOffset ,30.0f}}
	{
		mShooterLeft->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mShooterRight->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
		mShooterMiddle->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserRed01.png");
	}

	void ThreeWayShooter::ShootImpl()
	{
		mShooterLeft->Shoot();
		mShooterRight->Shoot();
		mShooterMiddle->Shoot();
	}

}