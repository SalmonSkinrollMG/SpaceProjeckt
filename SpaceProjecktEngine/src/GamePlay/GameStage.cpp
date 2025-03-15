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
		mStageFinished = true;
		StageFinished();
		onStageFinished.Broadcast();
	}

	void GameStage::StageFinished()
	{
		LOG("finished stage");
	}
}