#include "Enemy/UFOStage.h"
#include "framework/World.h"
#include "framework/MathUtility.h"
#include "Enemy/UFO.h"

namespace SPKT
{
	UFOStage::UFOStage(World* owningWorld)
		:GameStage(owningWorld),
		mSpawnInterval{4.0f},
		mSpawnAmount{10},
		mCurrentSpawnAmt{0},
		mUFOSpeed{200.0f}
	{
	}


	void UFOStage::StartStage()
	{
		mSpawnTimer = TimerManager::Get().SetTimer(GetWeakRef() , &UFOStage::SpawnUFO , mSpawnInterval,true);
	}

	void UFOStage::StageFinished()
	{
		TimerManager::Get().ClearTimer(mSpawnTimer);
	}

	Vector2D UFOStage::GetRandomSpawnLocation() const
	{
		auto windowSize = GetWorld()->GetWindowSize();

		float spawnLeft = RandomRange(-1 , 1);
		float spawnLocationX = 0;

		if (spawnLeft < 0)
		{
			spawnLocationX = windowSize.x + 100.0f;
		}
		else
		{
			spawnLocationX = -100.0f;
		}

		float spawnLocationY = RandomRange(0, windowSize.y);

		return Vector2D{ spawnLocationX , spawnLocationY };
	}

	void UFOStage::SpawnUFO()
	{
		Vector2D spawnLocation = GetRandomSpawnLocation();
		auto windowSize = GetWorld()->GetWindowSize();

		Vector2D center{ windowSize.x / 2.0f , windowSize.y / 2.0f };

		Vector2D directionToCenter{ center.x - spawnLocation.x , center.y - spawnLocation.y };

		Normalize(directionToCenter);

		Vector2D spawnVelocity = directionToCenter * mUFOSpeed;

		weakPtr<UFO> newUFO = GetWorld()->SpawnActor<UFO>(spawnVelocity);
		newUFO.lock()->SetActorPosition(spawnLocation);

		if (++mCurrentSpawnAmt == mSpawnAmount)
		{
			FinishStage();
		}

	}
}

