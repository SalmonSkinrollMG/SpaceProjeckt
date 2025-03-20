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

	
	private:

		float mWidth;
		uniquePtr<BulletShooter> mShooter1;
		uniquePtr<BulletShooter> mShooter2;
		uniquePtr<BulletShooter> mShooter3;
		uniquePtr<BulletShooter> mShooter4;

		virtual void ShootImpl()override;

	


	};
}