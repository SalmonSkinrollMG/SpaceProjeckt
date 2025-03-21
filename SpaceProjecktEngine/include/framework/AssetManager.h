#pragma region
#include <iostream>
#include "SFML/Graphics.hpp"
#include "framework/Core.h"

namespace SPKT {

	class AssetManager
	{

	public:
		static AssetManager& Get();
		sharedPtr<sf::Texture> LoadTexture(const std::string& Path);
		void CleanAssets();
		void SetRootDirectory(std::string& path);

	protected:
		AssetManager();

	private:
		static uniquePtr<AssetManager> assetManager;
		Dictonary <std::string, sharedPtr<sf::Texture>> mLoadedTextureMap;
		std::string mRootDirectory;
	};
}