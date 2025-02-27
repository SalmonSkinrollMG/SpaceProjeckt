#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "Enemy/Vanguard.h"
#include "player/Player.h"
#include "framework/AssetManager.h"
#include "config.h"


SPKT::Application* GetApplication()
{
	return new SPKT::GameApplication{};
}
namespace SPKT
{
	GameApplication::GameApplication()
		: Application(600 , 980 , "SpaceProjeckt", sf::Style::Titlebar | sf::Style::Close)
	{
		AssetManager::Get().SetRootDirectory(GetResourceDir());
		weakPtr<World> newWorld = LoadWorld<World>();
		ActorToDestory = newWorld.lock()->SpawnActor<Player>();
		ActorToDestory.lock()->SetActorPosition(Vector2D(300, 490));

		weakPtr<Vanguard> spaceShip = newWorld.lock()->SpawnActor<Vanguard>();
		spaceShip.lock()->SetActorPosition(Vector2D(100 , 100));
		spaceShip.lock()->SetTeamId(2);

	}

	void GameApplication::Tick(float Deltatime)
	{
		totalTime += Deltatime;
		if (totalTime >= 5.0f)
		{
			if (!ActorToDestory.expired())
			{
			//	ActorToDestory.lock()->Destroy();
			}
		}
		
	}
}

