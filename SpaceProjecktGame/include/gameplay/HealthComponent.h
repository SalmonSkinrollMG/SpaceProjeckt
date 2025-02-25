#pragma once 
#include "framework/Delegate.h"
namespace SPKT
{
	class HealthComponent {

	public:
		HealthComponent(float health , float maxHealth);

		void SetHealth(float amt);

		float GetHealth() const { return mHealth; }

		float GetMaxHealth() const { return mMaxHealth; }

		Delegate<float, float, float > onHealthChanged;

	private:

		void TakenDamage(float amt);
		void HealthEmpty();
		void HealthRegen(float amt);

		float mHealth;
		float mMaxHealth;
	};
}