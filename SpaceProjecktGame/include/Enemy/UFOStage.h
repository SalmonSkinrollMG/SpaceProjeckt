#pragma once
#include "Gameplay/GameStage.h"
#include <framework/TimerManager.h>

namespace SPKT
{
	class World;
	class UFOStage : public GameStage
	{

	public:

		UFOStage(World* owningWorld);

		virtual void StartStage() override;


	private:

		virtual void StageFinished() override;

		Vector2D GetRandomSpawnLocation() const;

		void SpawnUFO();

		int mSpawnAmount;
		float mSpawnInterval;
		int mCurrentSpawnAmt;
		float mUFOSpeed;

		TimerHandle mSpawnTimer;

	};
}