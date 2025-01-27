#include "framework/Application.h"
#include "framework/World.h"

namespace SPKT
{
	World::World(Application* owningApplication)
		:mOwningApplication{ nullptr },
		mBegunPlay{false},
		mActors{},
		mPendingActors{}
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBegunPlay)
		{
			BeginPlay();
			mBegunPlay = true;
		}
	}

	void World::TickInternal(float DeltaTime)
	{ 
		for (sharedPtr<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();

		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			
			if (iter->get()->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				iter->get()->TickInternal(DeltaTime);
				++iter;
			}
		}

		Tick(DeltaTime);
	}

	void World::Render(sf::RenderWindow& renderWindow)
	{
		for (auto& Actors : mActors)
		{
			Actors->Render(renderWindow);
		}
	}

	World::~World()
	{

	}

	void World::BeginPlay()
	{
		//LOG("started begin play in world");
	}

	void World::Tick(float DeltaTime)
	{
		//LOG("Running Tick in world with deltatime %f",DeltaTime);
	}
}