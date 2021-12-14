/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BOM_H
#define BOM_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Bom : public Entity
{
public:
	/// @brief Constructor
	Bom();
	/// @brief Destructor
	virtual ~Bom();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* Bom */
