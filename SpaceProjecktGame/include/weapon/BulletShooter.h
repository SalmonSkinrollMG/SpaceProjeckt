#pragma once
#include "SFML/System.hpp"
#include "weapon/WeaponBase.h"

namespace SPKT
{
	class BulletShooter : public WeaponBase
	{
	public:
		BulletShooter(Actor* owner , float shootingInterval = 1.0f);
		virtual bool IsInCooldown()const override;


	private:
		sf::Clock mShootingClock;
		float mShootingInterval;
		virtual void ShootImpl()override;
	};
}