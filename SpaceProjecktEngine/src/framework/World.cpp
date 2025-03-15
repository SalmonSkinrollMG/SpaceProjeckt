#include "framework/Application.h"
#include "framework/World.h"
#include "GamePlay/GameStage.h"

namespace SPKT
{
	World::World(Application* owningApplication)
		:mOwningApplication{ owningApplication },
		mBegunPlay{false},
		mActors{},
		mPendingActors{},
		mGameStages{},
		mCurrentStage{mGameStages.end()}
	{
	}

	void World::BeginPlayInternal()
	{
		if (!mBegunPlay)
		{
			BeginPlay();
			mBegunPlay = true;
			InitGameStage();
			StartStages();
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
			iter->get()->TickInternal(DeltaTime);
			++iter;
		}

		if (mCurrentStage != mGameStages.end())
		{
			mCurrentStage->get()->TickStage(DeltaTime);
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

	sf::Vector2u World::GetWindowSize() const
	{
		return mOwningApplication->GetWindowSize();
	}

	void World::RunCleanCycle()
	{
		for (auto iter = mActors.begin(); iter != mActors.end();)
		{

			if (iter->get()->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				++iter;
			}
		}
		
	}

	void World::AddStage(const sharedPtr<GameStage>& newStage)
	{
		mGameStages.push_back(newStage);
	}

	void World::BeginPlay()
	{
		//LOG("started begin play in world");
	}

	void World::Tick(float DeltaTime)
	{
		//LOG("Running Tick in world with deltatime %f",DeltaTime);
	}

	void World::InitGameStage()
	{

	}

	void World::AllGameStageFinished()
	{
		LOG("All Game Stages has Finished");
	}

	void World::NextGameStage()
	{
		mCurrentStage = mGameStages.erase(mCurrentStage);
		if (mCurrentStage != mGameStages.end())
		{
			mCurrentStage->get()->StartStage();
			mCurrentStage->get()->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
			
		}
		else
		{
			AllGameStageFinished();
		}
	}
	void World::StartStages()
	{
		mCurrentStage = mGameStages.begin();
		mCurrentStage->get()->StartStage();
		mCurrentStage->get()->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
	}
}