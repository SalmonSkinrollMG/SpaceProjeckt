#include "spaceShip/SpaceShip.h"

namespace SPKT {

	SpaceShip::SpaceShip(World* owningWorld, const std::string& texturePath)
		:Actor{ owningWorld, texturePath },
		mVelocity{},
		mHealthComponent{100.0f , 100.0f}
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

	void SpaceShip::Shoot()
	{
		
	}

	void SpaceShip::BeginPlay()
	{
		Actor::BeginPlay();
		SetPhysicsEnabled(true);
		mHealthComponent.onHealthChanged.BindAction(GetWeakRef() , &SpaceShip::OnHealthChanged);
		mHealthComponent.onHealthChanged.Broadcast(10.f , 44.f , 100.f);
	}

	void SpaceShip::OnHealthChanged(float amt, float health, float maxHealth)
	{
		LOG("Health is changed %f and now the current is %f of the %f maxHealth" , amt , health , maxHealth);
	}

}