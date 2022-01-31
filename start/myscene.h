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
#include <string>
#include <rt2d/text.h>




 /// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	//virtual void updateBullets(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	Background* background;
	std::vector<Pickup*> pickups; 
	Pickup* pickup;
	Bullet* bullet;
	Text* scoretext;
	int score;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	std::vector<int> lanes = {215, 640, 1065};

	std::vector<Bullet*> bullets;
};

#endif /* SCENE00_H */