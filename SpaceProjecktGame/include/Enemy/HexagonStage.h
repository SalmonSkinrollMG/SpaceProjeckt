#pragma once
#include "gamePlay/GameStage.h"
#include "framework/Core.h"
#include "framework/TimerManager.h"

namespace SPKT{

	class World;
	class HexagonStage : public GameStage
	{
	public:

		HexagonStage(World* owningWorld);

		virtual void StartStage() override;

	private:

		virtual void StageFinished() override;
		void SpawnHexagon();

		float mSpawnInterval;
		float mSpawnOffset;

		int mSpawnGroupAmt;
		int mCurrentSpawnCount;

		Vector2D mMidSpawnLocation;
		Vector2D mLeftSpawnLocation;
		Vector2D mRightSpawnLocation;

		TimerHandle mSpawnTimer;

	};
}