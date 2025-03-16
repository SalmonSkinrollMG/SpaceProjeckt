#pragma once
#include "Enemy/EnemySpaceShip.h"

namespace SPKT
{
	class World;
	class BulletShooter;
	class UFO : public EnemySpaceShip
	{

	public:

		UFO(World* owningWorld, Vector2D& velocity = Vector2D(0.0f, 150.0f), std::string texturePath = "SpaceShooterRedux/PNG/ufoGreen.png" , float rotationSpeed = 40.0f);

		virtual void Tick(float DeltaTime) override;

	private:

		virtual void Shoot() override;

		uniquePtr<BulletShooter> mShooter1;
		uniquePtr<BulletShooter> mShooter2;
		uniquePtr<BulletShooter> mShooter3;

		float mRotationSpeed;
	};
}