#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

namespace SPKT {
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		:mOwningWorld{ owningWorld },
		mHasBeganPlay{ false },
		mSprite{},
		mTexture{}
	{
		SetTexture(texturePath);
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			BeginPlay();
			mHasBeganPlay = true;
		}
	}

	void Actor::TickInternal(float DeltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(DeltaTime);
		}
	}

	void Actor::BeginPlay()
	{
	}

	void Actor::Tick(float DeltaTime)
	{
	}

	void Actor::SetTexture(const std::string& texturePath)
	{
		mTexture = AssetManager::Get().LoadTexture(texturePath);
		if (!mTexture)
		{
			return; //texture not load 
		}
		mSprite.setTexture(*mTexture);

		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;

		mSprite.setTextureRect({ sf::Vector2i{} , sf::Vector2i{textureWidth , textureHeight} }); //Draw from o to texture size. by default it covers the entire texure.
		CenterPivot();
	}

	void Actor::Render(sf::RenderWindow& renderWindow)
	{
		if (IsPendingDestroy())
		{
			return;
		}
		renderWindow.draw(mSprite);
	}

	void Actor::SetActorPosition(Vector2D& actorPosition)
	{
		mSprite.setPosition(actorPosition);
	}

	void Actor::SetActorRotation(Rotator1D actorRotation)
	{
		mSprite.setRotation(actorRotation);
	}

	void Actor::AddActorPositionOffset(Vector2D& actorOffset)
	{
		mSprite.setPosition(GetActorPosition() + actorOffset);
	}

	void Actor::AddActorRotationOffset(Rotator1D actorRotation)
	{
		mSprite.setRotation( GetActorRotation() + actorRotation);
	}

	Vector2D Actor::GetActorPosition()
	{
		return mSprite.getPosition();
	}

	Rotator1D Actor::GetActorRotation()
	{
		return mSprite.getRotation();
	}

	Vector2D Actor::GetActorForwardVector()
	{
		return RotationToVector(GetActorRotation());
	}

	Vector2D Actor::GetActorRightVector()
	{
		return RotationToVector(GetActorRotation() + 90.0f);
	}
	World* Actor::GetOwningWorld()
	{
		return mOwningWorld;
	}

	void Actor::CenterPivot()
	{
		sf::FloatRect bound = mSprite.getGlobalBounds();
		mSprite.setOrigin(bound.width/2.0f , bound.height/2.0f);
	}
}

