#include "Enemy/HexagonStage.h"
#include "framework/World.h"
#include "Enemy/Hexagon.h"

namespace SPKT
{
	HexagonStage::HexagonStage(World* owningWorld)
		: GameStage(owningWorld) , 
		mSpawnInterval{5.0f},
		mSpawnOffset{80.0f},
		mSpawnGroupAmt{5},
		mCurrentSpawnCount{0},
		mMidSpawnLocation{ owningWorld->GetWindowSize().x / 2.0f , -100.0f },
		mLeftSpawnLocation{ owningWorld->GetWindowSize().x / 2.0f + mSpawnOffset , -100.0f - mSpawnOffset},
		mRightSpawnLocation{ owningWorld->GetWindowSize().x / 2.0f - mSpawnOffset , -100.0f - mSpawnOffset}
	{
	}

	void HexagonStage::StartStage()
	{
		mSpawnTimer = TimerManager::Get().SetTimer(GetWeakRef() , &HexagonStage::SpawnHexagon , mSpawnInterval , true);
	}

	void HexagonStage::StageFinished()
	{
		TimerManager::Get().ClearTimer(mSpawnTimer);
	}

	void HexagonStage::SpawnHexagon()
	{
		weakPtr<Hexagon> newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorPosition(mMidSpawnLocation);

		newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorPosition(mLeftSpawnLocation);

		newHexagon = GetWorld()->SpawnActor<Hexagon>();
		newHexagon.lock()->SetActorPosition(mRightSpawnLocation);

		if (++mCurrentSpawnCount == mSpawnGroupAmt)
		{
			FinishStage();
		}
	}
}