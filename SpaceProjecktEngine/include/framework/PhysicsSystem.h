#pragma once
#include "framework/Core.h"
#include "box2d/b2_world.h"
#include "box2d/b2_contact.h"

namespace SPKT
{
	class Actor;

	class PhysicsContactListener :public b2ContactListener
	{
		virtual void BeginContact(b2Contact* contact) override;
		virtual void EndContact(b2Contact* contact) override;
	};

	class PhysicsSystem
	{
	public:
		void RemovePendingListners();
		static PhysicsSystem& Get();
		void Step(float DeltaTime);
		b2Body* AddListener(Actor* Listner);
		void RemoveListener(b2Body* ListnerToRemove);
		float GetPhysicsScale() { return mPhysicsScale; }

	protected:
		PhysicsSystem();

	private:
		static uniquePtr<PhysicsSystem> physicsSystem;
		b2World mPhysicsWorld;
		float mPhysicsScale;
		int mVelocityInteration;
		int mPosiitonInteration;
		PhysicsContactListener mContactListener;

		Set<b2Body*> mPendingListners;

	};
}