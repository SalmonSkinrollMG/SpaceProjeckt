#include "Enemy/UFO.h"
#include "weapon/BulletShooter.h"

namespace SPKT
{
		
	UFO::UFO(World* owningWorld, Vector2D& velocity, std::string texturePath, float rotationSpeed)
		:EnemySpaceShip(owningWorld, texturePath),
		mShooter1{ new BulletShooter{this , 0.5f , Vector2D{0.0f , 0.0f} , 0.0f } },
		mShooter2{ new BulletShooter{this , 0.5f , Vector2D{0.0f , 0.0f} , 120.0f} },
		mShooter3{ new BulletShooter{this , 0.5f , Vector2D{0.0f , 0.0f} , 240.0f} },
		mRotationSpeed{ rotationSpeed }
	{
		SetVelocity(velocity);
		SetActorRotation(180.0f);
	}
	void UFO::Tick(float DeltaTime)
	{
		EnemySpaceShip::Tick(DeltaTime);
		Shoot();
		AddActorRotationOffset(mRotationSpeed * DeltaTime);
	}


	void UFO::Shoot()
	{
		EnemySpaceShip::Shoot();
		mShooter1->Shoot();
		mShooter2->Shoot();
		mShooter3->Shoot();
	}
}