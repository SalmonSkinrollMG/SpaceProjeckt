#include "gameFramework/GameApplication.h"
#include "framework/Application.h"
#include "Level/GameLevelOne.h"
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
		weakPtr<GameLevelOne> newWorld = LoadWorld<GameLevelOne>();
	}
}

