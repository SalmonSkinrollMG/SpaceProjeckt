#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_contact.h"

#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"

namespace SPKT
{
	uniquePtr<PhysicsSystem> PhysicsSystem::physicsSystem{nullptr};


	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(uniquePtr<PhysicsSystem>{ new PhysicsSystem});
		}
		return *physicsSystem;
	}

	PhysicsSystem::PhysicsSystem()
		:mPhysicsWorld(b2Vec2(0.0f , 0.0f)),
		mPhysicsScale{0.01f},//box2s physics are scaled in meters . This variable can used to convert them to cm.
		mVelocityInteration{8},
		mPosiitonInteration{3},
		mContactListener{},
		mPendingListners{}
	{
		mPhysicsWorld.SetContactListener(&mContactListener);
		mPhysicsWorld.SetAllowSleeping(false);
	}

	void PhysicsSystem::Step(float DeltaTime)
	{
		RemovePendingListners();
		mPhysicsWorld.Step(DeltaTime, mVelocityInteration , mPosiitonInteration);
	}

	b2Body* PhysicsSystem::AddListener(Actor* Listner)
	{
		if (Listner->IsPendingDestroy())
		{
			return nullptr;
		}
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;

		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(Listner);

		bodyDef.position.Set(Listner->GetActorPosition().x * GetPhysicsScale(), Listner->GetActorPosition().y * GetPhysicsScale());

		bodyDef.angle = DegreesToRadians(Listner->GetActorRotation());

		b2Body* body = mPhysicsWorld.CreateBody(&bodyDef);

		b2PolygonShape shape;
		auto bounds = Listner->GetActorGlobalBounds();
		shape.SetAsBox(bounds.width/2.0f * GetPhysicsScale(), bounds.height/2.0f * GetPhysicsScale());

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.isSensor = true;

		body->CreateFixture(&fixtureDef);

		return body;
	}

	void PhysicsSystem::RemoveListener(b2Body* ListnerToRemove)
	{
		mPendingListners.insert(ListnerToRemove);
	}

	void PhysicsContactListener::BeginContact(b2Contact* contact)
	{
		Actor* ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		Actor* ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

		if (ActorA && !ActorA->IsPendingDestroy())
		{
			ActorA->OnActorOverlap(ActorB);
		}
		if (ActorB && !ActorB->IsPendingDestroy())
		{
			ActorB->OnActorOverlap(ActorA);
		}
	}

	void PhysicsContactListener::EndContact(b2Contact* contact)
	{
		Actor* ActorA = nullptr;
		Actor* ActorB = nullptr;

		if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
		{
			ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		}
		if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
		{
			ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
		}

		if (ActorA && !ActorA->IsPendingDestroy())
		{
			ActorA->OnActorEndOverlap(ActorB);
		}
		if (ActorB && !ActorB->IsPendingDestroy())
		{
			ActorB->OnActorEndOverlap(ActorA);
		}
	}

	void PhysicsSystem::RemovePendingListners()
	{
		for (auto listener : mPendingListners)
		{
			mPhysicsWorld.DestroyBody(listener);
		}
		mPendingListners.clear();
	}
}