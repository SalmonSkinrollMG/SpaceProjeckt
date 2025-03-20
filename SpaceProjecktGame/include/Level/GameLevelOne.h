#pragma once
#include "framework/World.h"
#include "framework/TimerManager.h"
namespace SPKT
{
	class PlayerSpaceShip;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApplication);

	private:

		virtual void InitGameStage() override;

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		weakPtr<PlayerSpaceShip> mPlayerSpaceShip;
		void PlayerSpaceShipDestroyed(Actor* destroyedSpaceShip);
		TimerHandle mTimerIndex;
		void GameOver();
	};
}