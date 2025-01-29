#pragma once
#include <string>
#include <framework/Actor.h>

namespace SPKT
{
	class World;
	class Bullet : public Actor
	{
	public:
		Bullet(World* owningWorld , Actor* owningActor , std::string texturePath , float bulletDamage = 10.0f , float bulletSpeed = 500.0f);

		void SetBulletSpeed(float bulletSpeed) { mBulletSpeed = bulletSpeed; }
		void SetBulletDamage(float bulletDamage) { mBulletDamage = bulletDamage; }

		float GetBulletDamage() { return mBulletDamage;}
		float GetBulletSpeed() { return mBulletSpeed; }

		virtual void Tick(float deltaTime)override;

		void Move(float deltaTime);


	private:
		Actor* mOwner;
		float mBulletDamage;
		float mBulletSpeed;
	};
}