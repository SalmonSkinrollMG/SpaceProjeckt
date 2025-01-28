#include "framework/AssetManager.h"
#include <iostream>
namespace SPKT 
{
	uniquePtr<AssetManager>AssetManager::assetManager{nullptr};

	AssetManager& AssetManager::Get()
	{
		if (!assetManager)
		{
			assetManager = uniquePtr<AssetManager>{ new AssetManager };
		}
		return *assetManager;
	}

	sharedPtr<sf::Texture> AssetManager::LoadTexture(const std::string& Path)
	{
		auto itr = mLoadedTextureMap.find(Path); // returns the itr
		if (itr != mLoadedTextureMap.end())
		{
			return itr->second; // return the value from the map using second keyworld
		}

		sharedPtr<sf::Texture> newTexture{ new sf::Texture };
		if (newTexture->loadFromFile( mRootDirectory + Path))
		{
			mLoadedTextureMap.insert({ Path, newTexture });
			return newTexture;
		}

		return sharedPtr<sf::Texture>(nullptr);
	}

	void AssetManager::CleanAssets()
	{
		for (auto itr = mLoadedTextureMap.begin(); itr != mLoadedTextureMap.end();)
		{
			if (itr->second.unique()) // true - Only assetManager holds the reference of the assets and is unique
			{
				LOG("asset cleaned");
				itr = mLoadedTextureMap.erase(itr);
			}
			else
			{
				itr++;
			}
		}
	}

	void AssetManager::SetRootDirectory(std::string& path)
	{
		mRootDirectory = path;
	}


	AssetManager::AssetManager()
		:mRootDirectory{}
	{

	}
}