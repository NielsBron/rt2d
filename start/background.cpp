/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "background.h"

Background::Background() : Entity()
{
	this->addSprite("assets/background.tga");
}

Background::~Background()
{

}

void Background::update(float deltaTime)
{
}
