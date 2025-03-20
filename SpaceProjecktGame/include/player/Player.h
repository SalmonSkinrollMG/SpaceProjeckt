#pragma once
#include "framework/Object.h"
#include "framework/Delegate.h"

namespace SPKT {

	class World;
	class PlayerSpaceShip;
	class Player : public Object
	{

	public:
		Player();
		weakPtr<PlayerSpaceShip> SpawnSpaceShip(World* owningWorld);
		weakPtr<PlayerSpaceShip> GetCurrentSpaceShip() const { return mCurrentSpaceShip; }

		void AddLifeCount(unsigned int count);
		int GetLifeCount() const { return mLifeCount; }

		void AddScore(unsigned int amt);
		int GetScore() const { return mScore; }

		Delegate<int> onLifeChanged;
		Delegate<int> onScoreChanged;
		Delegate<> onLifeExhausted;


	private:
		weakPtr<PlayerSpaceShip> mCurrentSpaceShip;
		unsigned int mLifeCount;
		unsigned int mScore;
	};
}