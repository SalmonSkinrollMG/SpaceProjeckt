#pragma once
#include "SFML/System.hpp"
#include "weapon/WeaponBase.h"
#include "framework/Core.h"

namespace SPKT
{
	class BulletShooter : public WeaponBase
	{
	public:
		BulletShooter(Actor* owner , float shootingInterval = 1.0f , Vector2D& positonOffset = Vector2D(0.0f , 0.0f), float rotationOffset = 0 , const std::string& bulletTexturePath = "SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
		virtual bool IsInCooldown()const override;
		void SetBulletTexturePath(const std::string& texture) { mBulletTexturePath = texture; }

		virtual void IncrementLevel(int amt)override;

	private:
		sf::Clock mShootingClock;
		float mShootingInterval;
		Vector2D mLocalPositionOffset;
		float mLocalRotationOffset;
		virtual void ShootImpl()override;
		std::string mBulletTexturePath;
	};
}