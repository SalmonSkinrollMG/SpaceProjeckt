#pragma once
#include <framework/Application.h>

namespace SPKT
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication::GameApplication();
		void Tick(float Deltatime);

		float totalTime = 0.0f;
		weakPtr<Actor> ActorToDestory;
	};
}