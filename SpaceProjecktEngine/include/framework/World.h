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

		template<typename ActorType>
		weakPtr<ActorType> SpawnActor();


	private:
		Application* mOwningApplication;
		bool mBegunPlay;
		void BeginPlay();
		void Tick(float DeltaTime);

		List<sharedPtr<Actor>> mActors;
		List<sharedPtr<Actor>> mPendingActors;
	};

	template<typename ActorType>
	weakPtr<ActorType> World::SpawnActor()
	{
		sharedPtr<ActorType> newActor{ new ActorType{this} };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}