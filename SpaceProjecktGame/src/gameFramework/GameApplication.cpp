#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
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

		weakPtr<SpaceShip> spaceShip = newWorld.lock()->SpawnActor<SpaceShip>();
		spaceShip.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
		spaceShip.lock()->SetActorPosition(Vector2D(100 , 100));

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

