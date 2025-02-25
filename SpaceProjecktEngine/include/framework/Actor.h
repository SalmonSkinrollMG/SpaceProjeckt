#pragma once
#include "framework/Core.h"
#include "framework/Object.h"
#include "box2d/b2_body.h"

namespace SPKT
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld , const std::string& texturePath = "");

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);

		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		
		void SetTexture(const std::string& texturePath);

		void Render(sf::RenderWindow& renderWindow);

		void SetActorPosition(Vector2D& actorPosition);
		void SetActorRotation(Rotator1D actorRotation);

		void AddActorPositionOffset(Vector2D& actorOffset);
		void AddActorRotationOffset(Rotator1D actorRotation);

		Vector2D GetActorPosition();
		Rotator1D GetActorRotation();

		Vector2D GetActorForwardVector();
		Vector2D GetActorRightVector();

		World* GetOwningWorld();
		
		sf::FloatRect GetActorGlobalBounds();

		bool CheckIfActorOutOfBound();

		void SetPhysicsEnabled(bool bEnabled);

		void OnActorOverlap(Actor* other);

		void OnActorEndOverlap(Actor* other);

		virtual void Destroy() override;

	private:

		void InitializePhysics();
		void DeinitializePhysics();

		void UpdatePhysicsBodyTransform();

		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		sharedPtr<sf::Texture> mTexture;

		b2Body* mPhysicsBody;
		bool mPhysicsEnabled;

		void CenterPivot();
	};

}