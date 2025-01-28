#pragma once

#include "framework/Core.h"

namespace SPKT
{
	class World;
	class Application
	{
	public:
		Application(unsigned int ScreenWidth , unsigned int ScreenHeight ,const std::string& Title , std::uint32_t Style);
		~Application();
		void Run();

		template<typename T>
		weakPtr<T> LoadWorld();
		
	private:
		void TickInternal(float DeltaTime);
		void RenderInternal();

		virtual void Tick(float DeltaTime);
		virtual void Render();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		sf::Clock mAssetCleanerClock;
		float mCleanInterval;

	public:
		
		sharedPtr<World> currentWorld;
		sf::Vector2u GetWindowSize()const;
	};

	template<typename T>
	inline weakPtr<T> Application::LoadWorld()
	{
		sharedPtr<T> newWorld{ new World(this) };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}