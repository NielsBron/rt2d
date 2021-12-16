/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "banaan2.h"

Banaan2::Banaan2() : Entity()
{
	this->addSprite("assets/banaan2.tga");
}

Banaan2::~Banaan2()
{

}

void Banaan2::update(float deltaTime)
{
	this->position.y += 200 * deltaTime;
}
