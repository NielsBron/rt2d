/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "pickup.h"
#include "myscene.h"

Pickup::Pickup() : Entity()
{

	t.start();

	int index = rand() % chances.size();
	int r = chances[index];
	if (r == 0) { type = Type::BOMB; this->addSprite("assets/bom.tga"); }
	if (r == 1) { type = Type::BANANA; this->addSprite("assets/banaan.tga"); }
	if (r == 2) { type = Type::BANANA2;  this->addSprite("assets/banaan2.tga"); }
	if (r == 3)
	std::cout << "type: " << r << std::endl;
}

Pickup::~Pickup()
{

}

void Pickup::update(float deltaTime)
{
	this->position.y += 400 * deltaTime;
}