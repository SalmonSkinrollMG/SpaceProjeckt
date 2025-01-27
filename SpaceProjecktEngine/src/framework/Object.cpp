#include "framework/Object.h"
#include "framework/Core.h"

namespace SPKT 
{
	Object::Object()
		:mIsPendingDestroy{false}
	{
	}

	Object::~Object()
	{
		LOG("Destruction is called on object");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
		LOG("Object marked for pending kill");
	}
}