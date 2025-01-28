#pragma once
#include "framework/Core.h"
#include "framework/Object.h"

namespace SPKT
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld , const std::string& texturePath = "");

		void BeginPlayInternal();
		void TickInternal(float DeltaTime);

		void BeginPlay();
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


	private:

		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		sharedPtr<sf::Texture> mTexture;

		void CenterPivot();
	};

}