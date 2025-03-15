#include "Enemy/TwinBladeStage.h"
#include "framework/World.h"
#include "Enemy/TwinBlade.h"

namespace SPKT 
{
	TwinBladeStage::TwinBladeStage(World* owningWorld)
		:GameStage(owningWorld),
		mSpawnInterval{ 1.5f },
		mSpawnLocationToCenter{ 100.0f },
		mLeftSpawnLocation{ owningWorld->GetWindowSize().x/2 - mSpawnLocationToCenter , -100.0f},
		mRightSpawnLocation{ owningWorld->GetWindowSize().x/2 + mSpawnLocationToCenter , -100.0f },
		mSpawnLocation{ mLeftSpawnLocation},
		mSpawnAmt{10},
		mCurrentSpawnCount{0}
	{
	}

	void TwinBladeStage::StartStage()
	{
		mSpawnTimerHandle = TimerManager::Get().SetTimer(GetWeakRef(), &TwinBladeStage::SpawnTwinBlade, mSpawnInterval, true);
	}



	void TwinBladeStage::SpawnTwinBlade()
	{
		weakPtr<TwinBlade> newVanguard = GetWorld()->SpawnActor<TwinBlade>();
		newVanguard.lock()->SetActorPosition(mSpawnLocation);
		if (mSpawnLocation ==  mLeftSpawnLocation)
		{
			mSpawnLocation = mRightSpawnLocation;
		}
		else
		{
			mSpawnLocation = mLeftSpawnLocation;
		}
		++mCurrentSpawnCount;

		if (mCurrentSpawnCount == mSpawnAmt)
		{
			FinishStage();
		}
	}

	void TwinBladeStage::StageFinished()
	{
		GameStage::StageFinished();
		TimerManager::Get().ClearTimer(mSpawnTimerHandle);
	}
}