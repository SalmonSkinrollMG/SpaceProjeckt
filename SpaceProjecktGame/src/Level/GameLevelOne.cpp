#include "Level/GameLevelOne.h"
#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "GamePlay/WaitStage.h"
#include "Enemy/UFOStage.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/VanguardStage.h"
#include "Enemy/TwinBladeStage.h"
#include "player/PlayerSpaceShip.h"
#include "player/PlayerManager.h"

namespace SPKT
{
	GameLevelOne::GameLevelOne(Application* owningApplication)
		:World(owningApplication)
	{
		
		
	}

	void GameLevelOne::InitGameStage()
	{
		AddStage(sharedPtr<UFOStage>(new UFOStage(this)));
		AddStage(sharedPtr<HexagonStage>(new HexagonStage(this)));
		AddStage(sharedPtr<VanguardStage>(new VanguardStage(this)));
		AddStage(sharedPtr<WaitStage>(new WaitStage(this)));
		AddStage(sharedPtr<TwinBladeStage>(new TwinBladeStage(this)));
	}

	void GameLevelOne::BeginPlay()
	{
		Player newPlayer = PlayerManager::Get().CreateNewPlayer();
		mPlayerSpaceShip = newPlayer.SpawnSpaceShip(this);
		mPlayerSpaceShip.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceShipDestroyed);
	}

	void GameLevelOne::Tick(float DeltaTime)
	{

	}
	void GameLevelOne::PlayerSpaceShipDestroyed(Actor* destroyedSpaceShip)
	{
		mPlayerSpaceShip = PlayerManager::Get().GetPlayer()->SpawnSpaceShip(this);
		if (!mPlayerSpaceShip.expired())
		{
			mPlayerSpaceShip.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceShipDestroyed);
		}
		else
		{
			GameOver();
		}

	}
	void GameLevelOne::GameOver()
	{
		LOG("---------------------------------------------------------------");
	}
}
