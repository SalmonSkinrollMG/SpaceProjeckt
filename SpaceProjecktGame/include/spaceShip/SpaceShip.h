#pragma once
#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/Core.h"
#include "gameplay/HealthComponent.h"

namespace SPKT
{
	class SpaceShip :public Actor
	{
	public:

		SpaceShip(World* owningWorld, const std::string& texturePath = "");
		virtual void Tick(float DeltaTime)override;

		void SetVelocity(const Vector2D& newVelocity);

		Vector2D GetVelocity() const {
			return mVelocity;
		};

		virtual void Shoot();

		virtual void BeginPlay() override;

		void OnHealthChanged(float amt, float health, float maxHealth);

	private:
		Vector2D mVelocity;
		HealthComponent mHealthComponent;
	};
}