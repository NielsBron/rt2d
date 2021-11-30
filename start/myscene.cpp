/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.   
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/1.2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Make myentity go to middle lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::S)) {
		myentity->position = Point2(SWIDTH / 2, SHEIGHT / 1.2);
	}
	
	// ###############################################################
	// Make myentity go to left lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::A)) {
		myentity->position = Point2(SWIDTH / 6, SHEIGHT / 1.2);
	}

	// ###############################################################
	// Make myentity go to right lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::D)) {
		myentity->position = Point2(SWIDTH / 1.2, SHEIGHT / 1.2);
	}
}
