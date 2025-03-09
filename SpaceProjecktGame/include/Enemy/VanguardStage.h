#pragma once
#include "gamePlay/GameStage.h"
#include "framework/TimerManager.h"

namespace SPKT
{
	class World;
	class VanguardStage : public GameStage
	{
	public:
		VanguardStage(World* owningWorld);
		virtual void StartStage() override;

		virtual void StageFinished() override;

	private:

		float mSpawnInterval;
		float mSwitchInterval;
		float mSpawnDistanceToEdge;

		Vector2D mLeftSpawnLocation;
		Vector2D mRightSpawnLocation;
		Vector2D mSpawnLocation;

		TimerHandle mSpawnTimerHandle;
		TimerHandle mSwitchTimerHandle;

		int mRowsToSpawn;
		int mRowSpawnCount;

		int mVanguardPerRow;
		int mCurrentRowVanguardCount;

		
		void SpawnVanguard();
		void SwitchRow();

	};
}