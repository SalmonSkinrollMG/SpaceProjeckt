#pragma once
#include <memory>
#include <framework/Core.h>

namespace SPKT
{
	class Object : public std::enable_shared_from_this<Object>
	{
	public:
		Object();
		virtual ~Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return mIsPendingDestroy; };

		weakPtr<Object> GetWeakRef();
		weakPtr<const Object> GetWeakRef() const;

	private:
		bool mIsPendingDestroy;

	};

}