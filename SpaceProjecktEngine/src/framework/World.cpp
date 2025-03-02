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
		mCurrentStageIndex{-1},
		mGameStages{}
	{
	}

	void World::BeginPlayInternal()
	{
		if (!mBegunPlay)
		{
			BeginPlay();
			mBegunPlay = true;
			InitGameStage();
			NextGameStage();
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

		if (mCurrentStageIndex >= 0 && mCurrentStageIndex < mGameStages.size())
		{
			mGameStages[mCurrentStageIndex]->TickStage(DeltaTime);
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

		for (auto iter = mGameStages.begin(); iter != mGameStages.end();)
		{
			if (iter->get()->IsStageFinished())
			{
				iter = mGameStages.erase(iter);
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

	}

	void World::NextGameStage()
	{
		++mCurrentStageIndex;
		if (mCurrentStageIndex >= 0 && mCurrentStageIndex < mGameStages.size())
		{
			mGameStages[mCurrentStageIndex]->onStageFinished.BindAction(GetWeakRef(), &World::NextGameStage);
			mGameStages[mCurrentStageIndex]->StartStage();
		}
		else
		{
			AllGameStageFinished();
		}
	}
}