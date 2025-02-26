#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"
#include "framework/PhysicsSystem.h"

namespace SPKT {
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		:mOwningWorld{ owningWorld },
		mHasBeganPlay{ false },
		mSprite{},
		mTexture{},
		mPhysicsBody{nullptr},
		mPhysicsEnabled{false},
		mTeamId{GetNeutralTeamId()}
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
		UpdatePhysicsBodyTransform();
	}

	void Actor::SetActorRotation(Rotator1D actorRotation)
	{
		mSprite.setRotation(actorRotation);
		UpdatePhysicsBodyTransform();
	}

	void Actor::AddActorPositionOffset(Vector2D& actorOffset)
	{
		SetActorPosition(GetActorPosition() + actorOffset);
	}

	void Actor::AddActorRotationOffset(Rotator1D actorRotation)
	{
		SetActorRotation(GetActorRotation() + actorRotation);
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
		return RotationToVector(GetActorRotation() - 90.0f); //converting forward vector toward Y+ axis
	}

	Vector2D Actor::GetActorRightVector()
	{
		return RotationToVector(GetActorRotation());
	}
	World* Actor::GetOwningWorld()
	{
		return mOwningWorld;
	}

	sf::FloatRect Actor::GetActorGlobalBounds()
	{
		return mSprite.getGlobalBounds();
	}

	bool Actor::CheckIfActorOutOfBound()
	{
		float windowWidth = GetOwningWorld()->GetWindowSize().x;
		float windowHeight = GetOwningWorld()->GetWindowSize().y;


		//width and height are the buffer for half size of the actor.
		float width = GetActorGlobalBounds().width; 
		float height = GetActorGlobalBounds().height;

		Vector2D actorPosition = GetActorPosition();

		if (actorPosition.x < -width) // less than zero and half size of the sprite in x axis 
		{
			return true;
		}
		if (actorPosition.x > windowWidth + width) //greater than zero and half size of the sprite in x axis
		{
			return true;
		}
		if (actorPosition.y < -height)//less than zero and half size of the sprite in y axis
		{
			return true;
		}
		if (actorPosition.y > windowWidth + height)//greater than zero and half size of the sprite in y axis
		{
			return true;
		}
		return false;
	}

	void Actor::SetPhysicsEnabled(bool bEnabled)
	{
		mPhysicsEnabled = bEnabled;

		if (bEnabled)
		{
			InitializePhysics();
		}
		else
		{
			DeinitializePhysics();
		}
	}

	void Actor::OnActorOverlap(Actor* other)
	{
		LOG("OVerlapped");
	}

	void Actor::OnActorEndOverlap(Actor* other)
	{
		LOG("End Overlapped");
	}

	void Actor::Destroy()
	{
		DeinitializePhysics();
		Object::Destroy();
	}

	bool Actor::IsOtherHostile(Actor* other)
	{
		if (GetTeamId() == GetNeutralTeamId() || other->GetTeamId() == GetNeutralTeamId())
		{
			return false;
		}
		return GetTeamId() != other->GetTeamId();
	}

	void Actor::ApplyDamage(float amt)
	{
		//////damage
	}

	void Actor::InitializePhysics()
	{
		if (!mPhysicsBody)
		{
			mPhysicsBody = PhysicsSystem::Get().AddListener(this);
		}
	}

	void Actor::DeinitializePhysics()
	{
		if (mPhysicsBody)
		{
			PhysicsSystem::Get().RemoveListener(mPhysicsBody);
			mPhysicsBody = nullptr;
		}
	}

	void Actor::UpdatePhysicsBodyTransform()
	{
		if (mPhysicsBody)
		{
			float physicsScale = PhysicsSystem::Get().GetPhysicsScale();
			b2Vec2 position{ GetActorPosition().x * physicsScale , GetActorPosition().y * physicsScale };
			float angle = DegreesToRadians(GetActorRotation());

			mPhysicsBody->SetTransform(position, angle);
		}
	}

	void Actor::CenterPivot()
	{
		sf::FloatRect bound = mSprite.getGlobalBounds();
		mSprite.setOrigin(bound.width/2.0f , bound.height/2.0f);
	}
}

