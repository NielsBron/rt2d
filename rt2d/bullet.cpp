/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

Bullet::Bullet() : Entity()
{
	this->addSprite("assets/playertest.tga");
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	position += velocity;
}
