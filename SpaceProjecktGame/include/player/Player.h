#pragma once
#include "spaceShip/SpaceShip.h"
#include "framework/Core.h"

namespace SPKT
{
	class Player : public SpaceShip
	{
	public:
		Player(World* owningWorld , const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

		virtual void Tick(float deltaTime)override;

	private:
		void HandleInput();
		void ConsumeInput(float deltaTime);
		void ClampPlayerInWindow();

		Vector2D mInputVector;
		float mSpeed;

	};
}