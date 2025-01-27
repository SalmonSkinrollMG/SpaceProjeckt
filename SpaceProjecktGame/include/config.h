#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //Relese
	return "assets/";
#else
	return "C:/Users/sarat/Documents/Projects/SpaceProjeckt/SpaceProjecktGame/assets/";
#endif

}
