#include "player/Player.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace SPKT {
	Player::Player(World* owningWorld, const std::string& path)
		:SpaceShip(owningWorld , path),
		mInputVector{},
		mSpeed{200.0f},
		mBulletShooter{ new BulletShooter{this , 0.1f} }
	{
		SetTeamId(1);
	}

	void Player::Tick(float deltaTime)
	{
		SpaceShip::Tick(deltaTime);
		HandleInput();
		ConsumeInput(deltaTime);
	}

	void Player::Shoot()
	{
		if (mBulletShooter)
		{
			mBulletShooter->Shoot();
		}
	}

	void Player::HandleInput()
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

	void Player::ConsumeInput(float deltaTime)
	{
		SetVelocity(mInputVector * mSpeed);
		mInputVector.x = mInputVector.y = 0;
	}

	void Player::ClampPlayerInWindow()
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