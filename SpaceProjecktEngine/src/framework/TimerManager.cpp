#include "framework/TimerManager.h"

namespace SPKT {

	unsigned int TimerHandle::timerKeyCounter = 0;

	TimerHandle::TimerHandle()
		:mTimerKey{GetNextTimerKey()}
	{

	}

	Timer::Timer(weakPtr<Object> weakRef,std::function<void()> callback, float duration, bool repeat)
		:mListner{weakRef , callback},
		mDuration{duration},
		mRepeat{repeat},
		mTimerCounter{0.0f},
		mExpired{false}
	{
		 
	}

	void Timer::TickTime(float deltaTime)
	{
		if (Expired())
		{
			return;
		}
		mTimerCounter += deltaTime;

		if (mTimerCounter >= mDuration)
		{
			mListner.second();

			if (mRepeat)
			{
				mTimerCounter = 0.0f;
			}
			else
			{
				SetExpired();
			}
		}
	}

	bool Timer::Expired() const
	{
		return mExpired || mListner.first.expired() || mListner.first.lock()->IsPendingDestroy();
	}

	void Timer::SetExpired()
	{
		mExpired = true;
	}


	uniquePtr<TimerManager> TimerManager::mTimerManager{ nullptr };

	TimerManager& TimerManager::Get()
	{
		if (!mTimerManager)
		{
			mTimerManager = std::move(uniquePtr<TimerManager>(new TimerManager()));
		}
		return *mTimerManager;
	}

	void TimerManager::UpdateTimer(float deltaTime)
	{
		for (auto iter = mTimers.begin(); iter != mTimers.end();)
		{
			if (iter->second.Expired())
			{
				iter = mTimers.erase(iter);
			}
			else
			{
				iter->second.TickTime(deltaTime);
				++iter;
			}
		}
	}

	void TimerManager::ClearTimer(TimerHandle  timerHandle)
	{
		auto iter = mTimers.find(timerHandle);

		if (iter != mTimers.end())
		{
			iter->second.SetExpired();
		}
	}

	bool operator==(const TimerHandle& lhs, const TimerHandle& rhs)
	{
		return lhs.GetTimerKey() == rhs.GetTimerKey();
	}

	TimerManager::TimerManager()
		:mTimers{}
	{

	}
	
	

}