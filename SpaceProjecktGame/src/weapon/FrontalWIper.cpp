#include "weapon/FrontalWiper.h"

namespace SPKT
{
	FrontalWiper::FrontalWiper(Actor* owner, float cooldownTime, Vector2D& localOffset, float width)
		:WeaponBase{ owner },
		mWidth{width},
		mShooter1{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y - width / 2.0f}} },
		mShooter2{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y - width / 6.0f}} },
		mShooter3{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y + width / 6.0f}} },
		mShooter4{ new BulletShooter{owner , cooldownTime , Vector2D{localOffset.x , localOffset.y + width / 2.0f}} },
		mShooter5{ new BulletShooter{owner , 0.1 , Vector2D{localOffset.x , localOffset.y - width }}},
		mShooter6{ new BulletShooter{owner , 0.1 , Vector2D{localOffset.x , localOffset.y + width }}}
	{
		mShooter1->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
		mShooter2->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		mShooter3->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		mShooter4->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
		mShooter5->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		mShooter6->SetBulletTexturePath("SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
	}
	void FrontalWiper::IncrementLevel(int amt)
	{
		WeaponBase::IncrementLevel(amt);
		mShooter1->IncrementLevel(amt);
		mShooter2->IncrementLevel(amt);
		mShooter3->IncrementLevel(amt);
		mShooter4->IncrementLevel(amt);
		mShooter5->IncrementLevel(amt);
		mShooter6->IncrementLevel(amt);
	}
	void FrontalWiper::ShootImpl()
	{
		mShooter1->Shoot();
		mShooter2->Shoot();
		mShooter3->Shoot();
		mShooter4->Shoot();
		if (GetCurrentLevel() == GetMaxLevl())
		{
			mShooter5->Shoot();
			mShooter6->Shoot();
		}
	}
}
