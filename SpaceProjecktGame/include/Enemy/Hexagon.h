#pragma once
#include"Enemy/EnemySpaceShip.h"
#include <weapon/BulletShooter.h>

namespace SPKT
{
	class Hexagon : public EnemySpaceShip
	{
	public:
		Hexagon(World* owningWorld, std::string texturePath = "SpaceShooterRedux/PNG/Enemies/enemyGreen4.png" , Vector2D velocity = Vector2D(0.0f, 150.0f));
		virtual void Tick(float deltaTime) override;
	private:

		virtual void Shoot() override;

		uniquePtr<BulletShooter> mBulletShooter1;
		uniquePtr<BulletShooter> mBulletShooter2;
		uniquePtr<BulletShooter> mBulletShooter3;
		uniquePtr<BulletShooter> mBulletShooter4;
		uniquePtr<BulletShooter> mBulletShooter5;
		uniquePtr<BulletShooter> mBulletShooter6;

	};
}