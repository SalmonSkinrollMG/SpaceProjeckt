#include "gameplay/HealthComponent.h"
#include "framework/Core.h"

namespace SPKT
{
	HealthComponent::HealthComponent(float health, float maxHealth)
		:mHealth{health},
		mMaxHealth{maxHealth}
	{
	}

	void HealthComponent::SetHealth(float amt)
	{
		if (amt == 0) return;
		if (mHealth == 0) return;

		mHealth += amt;

		if (mHealth < 0)
		{
			mHealth = 0;
		}
		if (mHealth > mMaxHealth)
		{
			mHealth = mMaxHealth;
		}
		if (amt < 0)
		{
			TakenDamage(-amt);
			if (mHealth <= 0)
			{
				HealthEmpty();
			}
		}
		onHealthChanged.Broadcast(amt , mHealth , mMaxHealth);
	}

	void HealthComponent::TakenDamage(float amt)
	{
		onDamageTaken.Broadcast(amt, mHealth, mMaxHealth);
	}

	void HealthComponent::HealthEmpty()
	{
		onHealthEmpty.Broadcast();
	}
}