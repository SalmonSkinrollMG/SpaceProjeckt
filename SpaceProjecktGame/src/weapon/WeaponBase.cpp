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
	WeaponBase::WeaponBase(Actor* owner)
		:mOwner{owner}
	{
	}
}