#pragma once
#include "gameplay/GameStage.h"
#include <framework/TimerManager.h>

namespace SPKT
{
	class World;
	class TwinBladeStage : public GameStage
	{
	public:
		TwinBladeStage(World* owningWorld);
		virtual void StartStage() override;

		virtual void StageFinished() override;

	private:

		float mSpawnInterval;
		float mSpawnLocationToCenter;

		Vector2D mLeftSpawnLocation;
		Vector2D mRightSpawnLocation;
		Vector2D mSpawnLocation;

		TimerHandle mSpawnTimerHandle;

		int mSpawnAmt;
		int mCurrentSpawnCount;

		void SpawnTwinBlade();

	};
}