#pragma once
#include "framework/Object.h"
#include "framework/Delegate.h"

namespace SPKT {

	class World;
	class GameStage : public Object
	{
	public:
		GameStage(World* owningWorld);

		const World* GetWorld() const { return mWorld; }
		World* GetWorld() { return mWorld; }

		Delegate<> onStageFinished;

		virtual void StartStage();
		virtual void TickStage(float DeltaTime);
		void FinishStage();

		bool IsStageFinished() { return mStageFinished; }

		virtual void StageFinished();

	private:

		bool mStageFinished;
		World* mWorld;

	};
}