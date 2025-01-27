//std libraries
#include <iostream>

//local directories
#include "framework/Application.h"
#include "framework/World.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"

namespace SPKT
{

	Application::Application(unsigned int ScreenWidth, unsigned int ScreenHeight, const std::string& Title, std::uint32_t Style)
		:mWindow{ sf::VideoMode(ScreenWidth, ScreenHeight), Title ,Style },
		mTargetFrameRate{ 60.0f },
		mTickClock{},
		currentWorld{ nullptr },
		mAssetCleanerClock{},
		mCleanInterval{2.0f}
	{
	
	}

	Application::~Application()
	{

	}


	void Application::Run()
	{
		mTickClock.restart();//starting the clock by resetting it.
		float elapsedTime = 0.0f;
		float targetDeltaTime = 1.0f / mTargetFrameRate;


		//Almight GameLoop ********
		while (mWindow.isOpen())//Game loop runs until the window is open.
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))//loop runs only during a window event.
			{
				if (windowEvent.type == sf::Event::EventType::Closed)//indicates close button in a window.
				{
					mWindow.close();
				}
			}

			/*
			* frameDeltaTime is the actual fps pushed.
			* Add elapsed time up until it reaches target delta time . Once it reaches the target deltaime-
			* -Subract elapsed time with target to keep the remaining time(Next frame).
			*/

			float frameDeltaTime = mTickClock.restart().asSeconds();
			elapsedTime += frameDeltaTime; //clock returns elapsedtime in seconds
			

			
			while (elapsedTime > targetDeltaTime)
			{
				elapsedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::TickInternal(float DeltaTime)
	{
		Tick(DeltaTime);
		if (currentWorld)
		{
			currentWorld->TickInternal(DeltaTime);
		}
		if (mAssetCleanerClock.getElapsedTime().asSeconds() >= mCleanInterval)
		{
			mAssetCleanerClock.restart();
			AssetManager::Get().CleanAssets();
		}
	}
	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();//ovveridden in child

		mWindow.display();
	}
	void Application::Tick(float DeltaTime)
	{

	}
	void Application::Render()
	{
		currentWorld->Render(mWindow);
	}
}