/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BANAAN2_H
#define BANAAN2_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Banaan2 : public Entity
{
public:
	/// @brief Constructor
	Banaan2();
	/// @brief Destructor
	virtual ~Banaan2();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* Banaan2 */
