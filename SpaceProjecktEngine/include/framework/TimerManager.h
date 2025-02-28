#pragma once
#include <functional>
#include "framework/Core.h"
#include "framework/Object.h"

namespace SPKT {

	struct TimerHandle
	{
	public:
		TimerHandle();
		unsigned int GetTimerKey() const { return mTimerKey; }
	private:
		unsigned int mTimerKey;
		static unsigned int timerKeyCounter;
		static unsigned int GetNextTimerKey() { return ++timerKeyCounter; }
	};

	struct TimerHandleHashFunction
	{
	public:

		std::size_t operator()(const TimerHandle& timerHandle) const
		{
			return timerHandle.GetTimerKey();
		}
	};

	bool operator==(const TimerHandle& lhs, const TimerHandle& rhs);

	struct Timer
	{
	public:
		Timer(weakPtr<Object> weakRef, std::function<void()> callback, float duration, bool repeat);
		void TickTime(float deltaTime);
		bool Expired() const;
		void SetExpired();

	private:
		std::pair<weakPtr<Object>, std::function<void()>> mListner;

		float mDuration;
		bool mRepeat;
		float mTimerCounter;
		bool mExpired;
	
	};

	class TimerManager
	{
	public:
		static TimerManager& Get();

		template <typename ClassName>
		TimerHandle SetTimer(weakPtr<Object> weakRef, void(ClassName::* callback)(), float duration, bool bRepeat)
		{
			TimerHandle newHandle{};
			mTimers.insert({ newHandle,Timer(weakRef, [=] {(static_cast<ClassName*>(weakRef.lock().get())->*callback)(); } , duration , bRepeat) });
			return newHandle;
		}

		void UpdateTimer(float deltaTime);
		void ClearTimer(TimerHandle timerHandle);

	protected:
		TimerManager();
	private:
		static uniquePtr<TimerManager> mTimerManager;
		Dictonary<TimerHandle ,Timer ,TimerHandleHashFunction> mTimers;
	};
}