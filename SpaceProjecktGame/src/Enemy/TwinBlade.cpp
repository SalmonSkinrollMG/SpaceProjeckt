#include "Enemy/TwinBlade.h"
#include "weapon/BulletShooter.h"

namespace SPKT
{
    TwinBlade::TwinBlade(World* owningWorld, std::string texturePath, Vector2D velocity)
        : EnemySpaceShip(owningWorld, texturePath),
        mBulletShooterLeft{ new BulletShooter{this , 1.0f , Vector2D{50.0f , -20.f}, 0.0f } },
        mBulletShooterRight{ new BulletShooter{this , 1.0f , Vector2D{50.0f , 20.f}, 0.0f } }
    {

        SetVelocity(velocity);
        SetActorRotation(180.0f);
    }

    void TwinBlade::Tick(float deltaTime)
    {
        EnemySpaceShip::Tick(deltaTime);
        Shoot();
    }

    void TwinBlade::Shoot()
    {
        EnemySpaceShip::Shoot();
        mBulletShooterLeft->Shoot();
        mBulletShooterRight->Shoot();
    }
}