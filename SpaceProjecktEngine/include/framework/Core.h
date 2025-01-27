#pragma once

#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>
#include "SFML/Graphics.hpp"

namespace SPKT 
{

// --------------Core Variables---------------


template<typename T>
using uniquePtr = std::unique_ptr<T>;

template<typename T>
using sharedPtr = std::shared_ptr<T>;

template<typename T>
using weakPtr = std::weak_ptr<T>;

/*
* List - Standard Vector
*/
template<typename T>
using List = std::vector<T>;

/*
* Map - Ordered map with a Predicate (Descending size)
*/
template<typename keyType , typename valueType , typename predicate = std::less<keyType>>
using Map = std::map<keyType, valueType, predicate>;

/*
* Dictonary - Unordered map hashed with key Type
*/
template<typename keyType, typename valueType, typename hasher = std::hash<keyType>>
using Dictonary = std::unordered_map<keyType, valueType, hasher>;


/*
* Vector2D - using SFML library template sf::vector<float,float>
*/
using Vector2D = sf::Vector2f;


/*
* Roatator1D - using std float for roatotor and for 2d game 1D rotator is more than fine
*/
using Rotator1D = float;

//----------------------Macros-------------------

/*
* Logging macro with variable arguments
*/
#define LOG(M , ...) printf(M "\n",##__VA_ARGS__);

}