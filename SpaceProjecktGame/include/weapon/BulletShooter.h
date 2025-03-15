#pragma once
#include "SFML/System.hpp"
#include "weapon/WeaponBase.h"
#include "framework/Core.h"

namespace SPKT
{
	class BulletShooter : public WeaponBase
	{
	public:
		BulletShooter(Actor* owner , float shootingInterval = 1.0f , Vector2D& positonOffset = Vector2D(0.0f , 0.0f), float rotationOffset = 0);
		virtual bool IsInCooldown()const override;


	private:
		sf::Clock mShootingClock;
		float mShootingInterval;
		Vector2D mLocalPositionOffset;
		float mLocalRotationOffset;
		virtual void ShootImpl()override;
	};
}