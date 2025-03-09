#include "Level/GameLevelOne.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "Enemy/Vanguard.h"
#include "Enemy/VanguardStage.h"
#include "player/Player.h"
#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"

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
	}

	void GameLevelOne::BeginPlay()
	{

	}

	void GameLevelOne::Tick(float DeltaTime)
	{

	}
}
