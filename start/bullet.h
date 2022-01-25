/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYBULLET_H
#define MYBULLET_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Bullet : public Entity
{
public:
	/// @brief Constructor
	Bullet();

	Vector2 velocity = Vector2(0, 0);
	
	/// @brief Destructor
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	
	/* add your private declarations */
};

#endif /* MYBULLET_H */
