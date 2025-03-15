#pragma once
#include "Enemy/EnemySpaceShip.h"

namespace SPKT
{
	class BulletShooter;
	class TwinBlade : public  EnemySpaceShip
	{
	public:
		TwinBlade(World* owningWorld, std::string texturePath = "SpaceShooterRedux/PNG/Enemies/enemyGreen1.png", Vector2D velocity = Vector2D(0.0f, 150.0f));
		virtual void Tick(float deltaTime) override;
	private:

		virtual void Shoot() override;
		uniquePtr<BulletShooter> mBulletShooterLeft;
		uniquePtr<BulletShooter> mBulletShooterRight;
	};
}