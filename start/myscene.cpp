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

	srand(time(nullptr));

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.   
	myentity = new MyEntity();
	myentity->position = Point2(640, 600);

	background = new Background();
	background->position = Point2(640, 360);
	background->scale = Point2(1.25f, 1.4f);

	std::vector<int> lanes = {215, 640, 1065};


	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(myentity);

	for (size_t i = 0; i < lanes.size(); i++) {
		Pickup* pickup = new Pickup();
		pickup->position = Point2(lanes[i], -200);
		pickups.push_back(pickup);
		this->addChild(pickup);
	}
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(background);

	for (size_t i = 0; i < pickups.size(); i++) {
		this->removeChild(pickups[i]);
		delete pickups[i];
	}

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete background;
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
		myentity->scale = Point(0.8f, 0.8f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Make myentity go to middle lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::S)) {
		myentity->position = Point2(640, 600);
	}

	// ###############################################################
	// Make myentity go to left lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::A)) {
		myentity->position = Point2(215, 600);
	}

	// ###############################################################
	// Make myentity go to right lane
	// ###############################################################
	if (input()->getKeyDown(KeyCode::D)) {
		myentity->position = Point2(1065, 600);
	}

	// ###############################################################
	// Collide actions
	// ###############################################################

	Rectangle rect1 = Rectangle(myentity->position.x, myentity->position.y, 150, 150);

	int score = 0;

	for (size_t i = 0; i < pickups.size(); i++) {
		//std::cout << pickups[i]->position.y << " ";
		Rectangle rect2 = Rectangle(pickups[i]->position.x, pickups[i]->position.y, 150, 150);
		if (Collider::rectangle2rectangle(rect1, rect2)) {
			this->removeChild(pickups[i]);
			score ++;
			std::cout << "score: " << score << std::endl;
		}
	}

	// std:: cout<< std::endl;


}
