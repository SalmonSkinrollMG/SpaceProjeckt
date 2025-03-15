#include "Enemy/VanguardStage.h"
#include "framework/World.h"
#include "Enemy/Vanguard.h"


namespace SPKT
{
	VanguardStage::VanguardStage(World* owningWorld)
		:GameStage(owningWorld),
		mSpawnInterval{3.0f},
		mSwitchInterval{5.0f},
		mSpawnDistanceToEdge{100.0f},
		mLeftSpawnLocation{0.0f , 0.0f},
		mRightSpawnLocation{0.0f , 0.0f},
		mSpawnLocation{0.0f , 0.0f},
		mRowsToSpawn{2},
		mRowSpawnCount{0},
		mVanguardPerRow{3},
		mCurrentRowVanguardCount{0}
	{
	}

	void VanguardStage::StartStage()
	{
		auto windowSize = GetWorld()->GetWindowSize();

		mLeftSpawnLocation = Vector2D(mSpawnDistanceToEdge, -100.0f);
		mRightSpawnLocation = Vector2D(windowSize.x - mSpawnDistanceToEdge, -100.0f);

		SwitchRow();
	}

	void VanguardStage::SwitchRow()
	{
		if (mRowSpawnCount == mRowsToSpawn)
		{
			FinishStage();
			return;
		}

		if (mSpawnLocation == mLeftSpawnLocation)
		{
			mSpawnLocation = mRightSpawnLocation;
		}
		else
		{
			mSpawnLocation = mLeftSpawnLocation;
		}

		mSpawnTimerHandle = TimerManager::Get().SetTimer(GetWeakRef() , &VanguardStage::SpawnVanguard , mSpawnInterval , true);
		++mRowSpawnCount;
	}


	void VanguardStage::SpawnVanguard()
	{
		weakPtr<Vanguard> newVanguard = GetWorld()->SpawnActor<Vanguard>();
		newVanguard.lock()->SetActorPosition(mSpawnLocation);
		++mCurrentRowVanguardCount;
		if (mCurrentRowVanguardCount == mVanguardPerRow)
		{
			TimerManager::Get().ClearTimer(mSpawnTimerHandle);
			mSwitchTimerHandle = TimerManager::Get().SetTimer(GetWeakRef() , &VanguardStage::SwitchRow , mSwitchInterval , false);
			mCurrentRowVanguardCount = 0;
		}
	}

	void VanguardStage::StageFinished()
	{
		GameStage::StageFinished();
		TimerManager::Get().ClearTimer(mSpawnTimerHandle);
		TimerManager::Get().ClearTimer(mSwitchTimerHandle);
	}
}