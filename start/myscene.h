/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "myentity.h"
#include "background.h"
#include "banaan.h"
#include "banaan2.h"
#include "pickup.h"
#include "collider.h"
#include "bullet.h"
#include "poop.h"
#include <string>
#include <rt2d/text.h>




class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();
	virtual void update(float deltaTime);

private:
	MyEntity* myentity;
	Poop* poop;
	Background* background;
	std::vector<Pickup*> pickups; 
	Pickup* pickup;
	Bullet* bullet;
	Text* scoretext;
	int score;
	Timer t;
	std::vector<int> lanes = {215, 640, 1065};

	std::vector<Bullet*> bullets;
};

#endif