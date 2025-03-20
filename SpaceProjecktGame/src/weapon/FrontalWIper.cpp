#include "weapon/FrontalWiper.h"

namespace SPKT
{
	FrontalWiper::FrontalWiper(Actor* owner, float cooldownTime, Vector2D& localOffset, float width)
		:WeaponBase{ owner },
		mWidth{width},
		mShooter1{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y - width / 1.0f}} },
		mShooter2{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y - width / 3.0f}} },
		mShooter3{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y + width / 3.0f}} },
		mShooter4{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y + width / 1.0f}} }
	{
		mShooter1->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
		mShooter2->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		mShooter3->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		mShooter4->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
	}
	void FrontalWiper::ShootImpl()
	{
		mShooter1->Shoot();
		mShooter2->Shoot();
		mShooter3->Shoot();
		mShooter4->Shoot();
	}
}
