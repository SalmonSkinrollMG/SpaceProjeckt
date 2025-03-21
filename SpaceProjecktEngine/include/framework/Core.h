#pragma once

#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
* List - Standard Vector. Will store copies .  Has O(n) time complexit in search/find
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
* Set - Unordered set stores unique values rather storing copies like vector . Has O(1) time complexit in search/find
*/
template<typename T>
using Set = std::unordered_set<T>;

/*
* Vector2D - using SFML library template sf::vector<float,float>
*/

using Vector2D = sf::Vector2f;


/*
* Rotator1D - using std float for rotator and for 2d game 1D rotator is more than fine
*/
using Rotator1D = float;

/*
* uint8 - unsigned charater.
*/
using uint8 = unsigned char;

//----------------------Macros-------------------

/*
* Logging macro with variable arguments
*/
#define LOG(M , ...) printf(M "\n",##__VA_ARGS__);

}