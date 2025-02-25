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
		LOG("Object Destoryed");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}
	weakPtr<Object> Object::GetWeakRef()
	{
		return weak_from_this();
	}
	weakPtr<const Object> Object::GetWeakRef() const
	{
		return weak_from_this();
	}
}