#include "player/Player.h"
#include "framework/World.h"
#include "player/PlayerSpaceShip.h"

namespace SPKT 
{
	Player::Player()
		:mLifeCount{3},
		mScore{0},
		mCurrentSpaceShip{}
	{
	}

	weakPtr<PlayerSpaceShip> Player::SpawnSpaceShip(World* owningWorld)
	{
		if (mLifeCount > 0)
		{
			--mLifeCount;
			auto windowSize = owningWorld->GetWindowSize();
			mCurrentSpaceShip = owningWorld->SpawnActor<PlayerSpaceShip>();
			mCurrentSpaceShip.lock()->SetActorPosition(Vector2D(windowSize.x/2.0f , windowSize.y - 100.0f));
			onLifeChanged.Broadcast(mLifeCount);
			return mCurrentSpaceShip;
		}
		else
		{
			onLifeExhausted.Broadcast();
		}
		return weakPtr<PlayerSpaceShip>{};
	}

	void Player::AddLifeCount(unsigned int count)
	{
		if (count > 0)
		{
			mLifeCount += count;
			onLifeChanged.Broadcast(mLifeCount);
		}
	}

	void Player::AddScore(unsigned int amt)
	{
		if (amt > 0)
		{
			mScore = amt;
			onScoreChanged.Broadcast(amt);
		}
	}
}
