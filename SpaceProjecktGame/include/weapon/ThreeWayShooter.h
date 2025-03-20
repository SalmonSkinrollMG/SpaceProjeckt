#pragma once
#include "weapon/WeaponBase.h"
#include "framework/Core.h"
#include "weapon/BulletShooter.h"

namespace SPKT
{
	class ThreeWayShooter : public WeaponBase
	{
	public:
		ThreeWayShooter(Actor* owner, float cooldownTime = 0.3f, Vector2D& localOffset = Vector2D{ 0.0f,0.0f });


	private:

		uniquePtr<BulletShooter> mShooterLeft;
		uniquePtr<BulletShooter> mShooterRight;
		uniquePtr<BulletShooter> mShooterMiddle;

		virtual void ShootImpl()override;
	};
}