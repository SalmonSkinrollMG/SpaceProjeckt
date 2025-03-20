#pragma once
#include "framework/Core.h"
#include "player/Player.h"

namespace SPKT
{
	class PlayerManager
	{
	protected:
		PlayerManager();

	private:
		List<Player> mPlayers;
		static uniquePtr<PlayerManager> mPlayerManager;

	public:
		Player& CreateNewPlayer();

		Player* GetPlayer(int playerIndex = 0);
		const Player* GetPlayer(int playerIndex)const;

		static PlayerManager& Get();
	};
}