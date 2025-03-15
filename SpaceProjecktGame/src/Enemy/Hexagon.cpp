#include "Enemy/Hexagon.h"

namespace SPKT
{
	Hexagon::Hexagon(World* owningWorld, std::string texturePath , Vector2D velocity)
		:EnemySpaceShip(owningWorld , texturePath ),
		mBulletShooter1{ new BulletShooter{this , 1.0f , Vector2D{20.0f , 50.0f} , 30.0f}},
		mBulletShooter2{ new BulletShooter{this , 1.0f , Vector2D{50.0f , -50.0f} , -30.0f} },
		mBulletShooter3{ new BulletShooter{this , 1.0f , Vector2D{50.0f , 0.0f} , 0.0f} },
		mBulletShooter4{ new BulletShooter{this , 1.0f , Vector2D{-50.0f , 0.0f} , -180.0f} },
		mBulletShooter5{ new BulletShooter{this , 1.0f , Vector2D{-20.0f , 50.0f} , 120.0f} },
		mBulletShooter6{ new BulletShooter{this , 1.0f , Vector2D{-20.0f , -50.0f} , -120.0f} }
	{
		SetVelocity(velocity);
		SetActorRotation(180.0f);
	}

	void Hexagon::Tick(float deltaTime)
	{
		EnemySpaceShip::Tick(deltaTime);
		Shoot();
	}

	void Hexagon::Shoot()
	{
		EnemySpaceShip::Shoot();
		mBulletShooter1->Shoot();
		mBulletShooter2->Shoot();
		mBulletShooter3->Shoot();
		mBulletShooter4->Shoot();
		mBulletShooter5->Shoot();
		mBulletShooter6->Shoot();
	}
}