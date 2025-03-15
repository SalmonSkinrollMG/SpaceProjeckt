#include "Level/GameLevelOne.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "GamePlay/WaitStage.h"
#include "Enemy/VanguardStage.h"
#include "Enemy/TwinBladeStage.h"
#include "player/Player.h"

namespace SPKT
{
	GameLevelOne::GameLevelOne(Application* owningApplication)
		:World(owningApplication)
	{
		mPlayer = SpawnActor<Player>();
		mPlayer.lock()->SetActorPosition(Vector2D(300, 490));
		
	}

	void GameLevelOne::InitGameStage()
	{
		AddStage(sharedPtr<VanguardStage>(new VanguardStage(this)));
		AddStage(sharedPtr<WaitStage>(new WaitStage(this)));
		AddStage(sharedPtr<TwinBladeStage>(new TwinBladeStage(this)));
	}

	void GameLevelOne::BeginPlay()
	{

	}

	void GameLevelOne::Tick(float DeltaTime)
	{

	}
}
