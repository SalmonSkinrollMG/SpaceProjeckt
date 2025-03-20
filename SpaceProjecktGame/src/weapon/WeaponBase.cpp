#include "weapon/WeaponBase.h"
#include "framework/Actor.h"

namespace SPKT
{
	void WeaponBase::Shoot()
	{
		if (CanShoot() && !IsInCooldown())
		{
			ShootImpl();
		}
	}
	void WeaponBase::IncrementLevel(int amt)
	{
		if (mCurrentLevel == mMaxLevl)
		{
			return;
		}
		++mCurrentLevel;
	}

	WeaponBase::WeaponBase(Actor* owner)
		:mOwner{owner},
		mCurrentLevel{1},
		mMaxLevl{5}
	{
	}
}