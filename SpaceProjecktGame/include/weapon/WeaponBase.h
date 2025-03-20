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

		int GetCurrentLevel() const { return mCurrentLevel; }
		int GetMaxLevl() const { return mMaxLevl; }

		virtual void IncrementLevel(int amt =1);

	protected:
		WeaponBase(Actor* owner);

	private:
		Actor* mOwner;
		virtual void ShootImpl() = 0;

		int mCurrentLevel;
		int mMaxLevl;
	};

}