#pragma once
#include "framework/World.h"
#include "framework/TimerManager.h"
namespace SPKT
{
	class Player;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApplication);

		void OnTimerFUNC();

		

	private:

		virtual void InitGameStage() override;

		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		weakPtr<Player> mPlayer;
		TimerHandle mTimerIndex;
	};
}