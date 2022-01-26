/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef PICKUP_H
#define PICKUP_H

#include <rt2d/entity.h>

enum class Type { BOMB = 0, BANANA = 1, BANANA2 = 2 };

/// @brief The MyEntity class is the Entity implementation.
class Pickup : public Entity
{
public:
	/// @brief Constructor
	Pickup();
	/// @brief Destructor
	virtual ~Pickup();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Type type;
	Timer t;
	std::vector<int>chances={0,1,1,1,1,2,3,3,3,3}; //10 chances 10% voor bom / 40% voor banaan / 40 voor niks / 10 % voor kleine banaan

private:
	/* add your private declarations */
};

#endif /* Bom */
