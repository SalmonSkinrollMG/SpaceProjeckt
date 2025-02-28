#include "Level/GameLevelOne.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "Enemy/Vanguard.h"
#include "player/Player.h"
#include "framework/TimerManager.h"

namespace SPKT
{
	GameLevelOne::GameLevelOne(Application* owningApplication)
		:World(owningApplication)
	{
		mPlayer = SpawnActor<Player>();
		mPlayer.lock()->SetActorPosition(Vector2D(300, 490));

		weakPtr<Vanguard> spaceShip = SpawnActor<Vanguard>();
		spaceShip.lock()->SetActorPosition(Vector2D(100, 100));
		spaceShip.lock()->SetTeamId(2);
		
	}
	void GameLevelOne::OnTimerFUNC()
	{
		LOG("Timer is called");
		TimerManager::Get().ClearTimer(mTimerIndex);
	}

	void GameLevelOne::BeginPlay()
	{
		mTimerIndex = TimerManager::Get().SetTimer(GetWeakRef(), &GameLevelOne::OnTimerFUNC, 2.0f, true);
	}

	void GameLevelOne::Tick(float DeltaTime)
	{

	}
}
