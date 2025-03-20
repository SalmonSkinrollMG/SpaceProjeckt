#pragma once
#include "spaceShip/SpaceShip.h"
#include "framework/Core.h"

namespace SPKT
{
	class WeaponBase;
	class Player : public SpaceShip
	{
	public:
		Player(World* owningWorld , const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

		virtual void Tick(float deltaTime)override;

		virtual void Shoot()override;

		void SetWeapon(uniquePtr<WeaponBase>&& newWeapon);

	private:
		void HandleInput();
		void ConsumeInput(float deltaTime);
		void ClampPlayerInWindow();

		Vector2D mInputVector;
		float mSpeed;

		uniquePtr<WeaponBase> mPlayerWeapon;
	};
}