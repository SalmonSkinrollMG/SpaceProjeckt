#include "GamePlay/GameStage.h"
#include "framework/Core.h"

namespace SPKT
{
	GameStage::GameStage(World* owningWorld)
		:mWorld{owningWorld},
		mStageFinished{false}
	{
	}

	void GameStage::StartStage()
	{
		LOG("started stage");
	}

	void GameStage::TickStage(float DeltaTime)
	{
	}

	void GameStage::FinishStage()
	{
		onStageFinished.Broadcast();
		mStageFinished = true;
		StageFinished();
	}

	void GameStage::StageFinished()
	{
		LOG("finished stage");
	}
}