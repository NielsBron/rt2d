/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "pickup.h"

Pickup::Pickup() : Entity()
{
	int r = rand() % 3;
	if (r == 0) { type = Type::BOMB; this->addSprite("assets/bom.tga"); }
	if (r == 1) { type = Type::BANANA; this->addSprite("assets/banaan.tga"); }
	if (r == 2) { type = Type::BANANA2;  this->addSprite("assets/banaan2.tga"); }
	std::cout << "type: " << r << std::endl;
}

Pickup::~Pickup()
{

}

void Pickup::update(float deltaTime)
{
	this->position.y += 200 * deltaTime;
}
