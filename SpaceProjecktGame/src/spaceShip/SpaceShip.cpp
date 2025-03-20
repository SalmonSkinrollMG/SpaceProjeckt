#include "spaceShip/SpaceShip.h"
#include "framework/MathUtility.h"
#include "VFX/Explosion.h"

namespace SPKT {

	SpaceShip::SpaceShip(World* owningWorld, const std::string& texturePath)
		:Actor{ owningWorld, texturePath },
		mVelocity{},
		mHealthComponent{100.0f , 100.0f},
		mBlinkTime{0.0f},
		mBlinkDuration{0.5f},
		mBlinkColor{sf::Color::Red}
	{
	}

	void SpaceShip::Tick(float DeltaTime)
	{
		Actor::Tick(DeltaTime);
		AddActorPositionOffset(GetVelocity() * DeltaTime);
		UpdateBlink(DeltaTime);
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
		mHealthComponent.onDamageTaken.BindAction(GetWeakRef(), &SpaceShip::OnDamageTaken);
		mHealthComponent.onHealthEmpty.BindAction(GetWeakRef(), &SpaceShip::OnHealthEmpty);
	}

	void SpaceShip::ApplyDamage(float amt)
	{
		Actor::ApplyDamage(amt);
		mHealthComponent.SetHealth(-amt);
	}

	void SpaceShip::Blink()
	{
		if (mBlinkTime == 0)
		{
			mBlinkTime = mBlinkDuration;
		}
	}

	void SpaceShip::UpdateBlink(float deltaTime)
	{
		if (mBlinkTime > 0)
		{
			mBlinkTime -= deltaTime;
			mBlinkTime = mBlinkTime > 0 ? mBlinkTime : 0; // clamping

			GetActorSprite().setColor(LerpColor(sf::Color::White, mBlinkColor, mBlinkTime));
		}
	}

	void SpaceShip::Blow()
	{
		Explosion* exp = new Explosion();
		exp->SpawnExplosion(GetOwningWorld(), GetActorPosition());
		AfterBlow();
		Destroy();
		delete exp;
	}

	void SpaceShip::AfterBlow()
	{
	}


	void SpaceShip::OnHealthChanged(float amt, float health, float maxHealth)
	{
		LOG("Health is changed %f and now the current is %f of the %f maxHealth", amt, health, maxHealth);
	}

	void SpaceShip::OnDamageTaken(float amt, float health, float maxHealth)
	{
		Blink();
	}

	void SpaceShip::OnHealthEmpty()
	{
		Blow();
	}

}