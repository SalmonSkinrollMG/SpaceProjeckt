#include"player/PlayerManager.h"

namespace SPKT
{
	uniquePtr<PlayerManager> PlayerManager::mPlayerManager{ nullptr };
	PlayerManager::PlayerManager()
	{
	}

	Player& PlayerManager::CreateNewPlayer()
	{
		mPlayers.emplace(mPlayers.begin(), Player());
		return mPlayers.back();
	}
	Player* PlayerManager::GetPlayer(int playerIndex)
	{
		if (playerIndex >= 0 && playerIndex <= mPlayers.size())
		{
			return &mPlayers[playerIndex];
		}
		return nullptr;
	}
	const Player* PlayerManager::GetPlayer(int playerIndex) const
	{
		if (playerIndex >= 0 && playerIndex <= mPlayers.size())
		{
			return &mPlayers[playerIndex];
		}
		return nullptr;
	}
	PlayerManager& PlayerManager::Get()
	{
		if (!mPlayerManager)
		{
			mPlayerManager = std::move(uniquePtr<PlayerManager>{new PlayerManager});
		}
		return *mPlayerManager;
	}
}