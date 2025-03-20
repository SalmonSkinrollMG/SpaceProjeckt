#pragma once
#include "weapon/WeaponBase.h"
#include "framework/Core.h"
#include "weapon/BulletShooter.h"

namespace SPKT
{
	class FrontalWiper : public WeaponBase
	{
	public:
		FrontalWiper(Actor* owner, float cooldownTime = 0.3f, Vector2D& localOffset = Vector2D{ 0.0f,0.0f },float width = 60.0f);

		virtual void IncrementLevel(int amt);
	private:

		float mWidth;
		uniquePtr<BulletShooter> mShooter1;
		uniquePtr<BulletShooter> mShooter2;
		uniquePtr<BulletShooter> mShooter3;
		uniquePtr<BulletShooter> mShooter4;

		uniquePtr<BulletShooter> mShooter5;
		uniquePtr<BulletShooter> mShooter6;

		virtual void ShootImpl()override;

	


	};
}