#pragma once
#include "framework/Core.h"
#include "framework/Actor.h"

namespace SPKT
{
	class Application;
	class World
	{
	public:
		World(Application* owningApplication);
		void BeginPlayInternal();
		void TickInternal(float DeltaTime);
		void Render(sf::RenderWindow& renderWindow);

		virtual ~World();

		template<typename ActorType , typename... Args>
		weakPtr<ActorType> SpawnActor(Args... args);

		sf::Vector2u GetWindowSize() const;


	private:
		Application* mOwningApplication;
		bool mBegunPlay;
		void BeginPlay();
		void Tick(float DeltaTime);

		List<sharedPtr<Actor>> mActors;
		List<sharedPtr<Actor>> mPendingActors;
	};

	template<typename ActorType, typename... Args>
	weakPtr<ActorType> World::SpawnActor(Args... args)
	{
		sharedPtr<ActorType> newActor{ new ActorType{this , args...} };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}