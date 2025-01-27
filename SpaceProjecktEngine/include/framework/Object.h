#pragma once

namespace SPKT
{
	class Object 
	{
	public:
		Object();
		virtual ~Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return mIsPendingDestroy; };

	private:
		bool mIsPendingDestroy;

	};

}