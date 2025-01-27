#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
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
		weakPtr<World> newWorld = LoadWorld<World>();
		ActorToDestory = newWorld.lock()->SpawnActor<Actor>();
		ActorToDestory.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		ActorToDestory.lock()->SetActorPosition(Vector2D(300, 490));
		ActorToDestory.lock()->SetActorRotation(90);

	}
	void GameApplication::Tick(float Deltatime)
	{
		totalTime += Deltatime;
		if (totalTime >= 5.0f)
		{
			
		}
		if (!ActorToDestory.expired())
		{
			ActorToDestory.lock()->AddActorRotationOffset(2.0f);
		}
	}
}

