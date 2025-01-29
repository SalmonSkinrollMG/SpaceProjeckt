#pragma once

namespace SPKT
{
	class Actor;
	class WeaponBase
	{

	public:

		void Shoot();

		virtual bool CanShoot() const { return true; }
		virtual bool IsInCooldown() const { return false; }

		Actor* GetOwner() const { return mOwner; }

	protected:
		WeaponBase(Actor* owner);

	private:
		Actor* mOwner;
		virtual void ShootImpl() = 0;

	};

}