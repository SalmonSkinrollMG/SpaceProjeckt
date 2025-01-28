#include "spaceShip/SpaceShip.h"

namespace SPKT {

	SpaceShip::SpaceShip(World* owningWorld, const std::string& texturePath)
		:Actor{ owningWorld, texturePath },
		mVelocity{}
	{
	}

	void SpaceShip::Tick(float DeltaTime)
	{
		Actor::Tick(DeltaTime);
		AddActorPositionOffset(GetVelocity() * DeltaTime);
	}

	void SpaceShip::SetVelocity(const Vector2D& newVelocity)
	{
		mVelocity = newVelocity;
	}

}