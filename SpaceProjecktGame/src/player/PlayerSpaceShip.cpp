#include "player/PlayerSpaceShip.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"


namespace SPKT {
	PlayerSpaceShip::PlayerSpaceShip(World* owningWorld, const std::string& path)
		:SpaceShip(owningWorld , path),
		mInputVector{},
		mSpeed{200.0f},
		mPlayerWeapon{ new BulletShooter{this , 0.1f , Vector2D{50.0f , 0.0f} } }
	{
		SetTeamId(1);
	}

	void PlayerSpaceShip::Tick(float deltaTime)
	{
		SpaceShip::Tick(deltaTime);
		HandleInput();
		ConsumeInput(deltaTime);
	}

	void PlayerSpaceShip::Shoot()
	{
		if (mPlayerWeapon)
		{
			mPlayerWeapon->Shoot();
		}
	}

	void PlayerSpaceShip::SetWeapon(uniquePtr<WeaponBase>&& newWeapon)
	{
		if (mPlayerWeapon && typeid(*mPlayerWeapon.get()) == typeid(*newWeapon.get()))
		{
			mPlayerWeapon->IncrementLevel();
			return;
		}
		mPlayerWeapon = std::move(newWeapon);
 	}

	void PlayerSpaceShip::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			mInputVector.y = -1.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			mInputVector.y = 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mInputVector.x = -1.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mInputVector.x = 1.0f;
		}
		ClampPlayerInWindow();
		Normalize(mInputVector);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Shoot();
		}
	}

	void PlayerSpaceShip::ConsumeInput(float deltaTime)
	{
		SetVelocity(mInputVector * mSpeed);
		mInputVector.x = mInputVector.y = 0;
	}

	void PlayerSpaceShip::ClampPlayerInWindow()
	{
		sf::Vector2u windowSize = GetOwningWorld()->GetWindowSize();
		Vector2D playerPosition = GetActorPosition();

		if (playerPosition.x < 0.0f && mInputVector.x == -1)
		{
			mInputVector.x = 0.0f;
		}
		if (playerPosition.x > windowSize.x && mInputVector.x == 1)
		{
			mInputVector.x = 0.0f;
		}
		if (playerPosition.y < 0.0f && mInputVector.y == -1)
		{
			mInputVector.y = 0.0f;
		}
		if (playerPosition.y > windowSize.y && mInputVector.y == 1)
		{
			mInputVector.y = 0.0f;
		}
	}

}