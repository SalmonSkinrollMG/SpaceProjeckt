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
			if (amt <= 0)
			{
				HealthEmpty();
			}
		}
		else
		{
			HealthRegen(amt);
		}


	}

	void HealthComponent::TakenDamage(float amt)
	{
		LOG("Took Damage");
	}

	void HealthComponent::HealthEmpty()
	{
	}

	void HealthComponent::HealthRegen(float amt)
	{
	}
}