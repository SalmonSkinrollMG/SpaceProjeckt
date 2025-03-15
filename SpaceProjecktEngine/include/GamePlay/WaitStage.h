#pragma once 
#include "GamePlay/GameStage.h"


namespace SPKT
{
	class World;
	class WaitStage : public GameStage
	{
	public:
		WaitStage(World* owningWorld, float waitDuration = 5.0f);

		virtual void StartStage() override;

	private:

		float mWaitDuration;
	};
}