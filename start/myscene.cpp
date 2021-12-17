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
	myentity->position = Point2(640, 600);
	Line s1;
	s1.addPoint(-75, -75);
	s1.addPoint(75, -75);
	s1.addPoint(75, 75);
	s1.addPoint(-75, 75);
	s1.addPoint(-75, -75);
	myentity->addLine(&s1);

	background = new Background();
	background->position = Point2(640, 360);
	background->scale = Point2(1.25f, 1.4f);

	banaan = new Banaan();
	banaan->position = Point2(640, -100);
	Line s2;
	s2.addPoint(-75, -75);
	s2.addPoint(75, -75);
	s2.addPoint(75, 75);
	s2.addPoint(-75, 75);
	s2.addPoint(-75, -75);
	banaan->addLine(&s2);
	
	banaan2 = new Banaan2();
	banaan2->position = Point2(215, -100);
	Line s3;
	s3.addPoint(-75, -75);
	s3.addPoint(75, -75);
	s3.addPoint(75, 75);
	s3.addPoint(-75, 75);
	s3.addPoint(-75, -75);
	banaan2->addLine(&s3);

	bom = new Bom();
	bom->position = Point2(1065, -100);
	Line s4;
	s4.addPoint(-75, -75);
	s4.addPoint(75, -75);
	s4.addPoint(75, 75);
	s4.addPoint(-75, 75);
	s4.addPoint(-75, -75);
	bom->addLine(&s4);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(myentity);
	this->addChild(banaan);
	this->addChild(banaan2);
	this->addChild(bom);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(background);
	this->removeChild(banaan);
	this->removeChild(banaan2);
	this->removeChild(bom);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete background;
	delete banaan;
	delete banaan2;
	delete bom;
}

void MyScene::update(float deltaTime)
{

	Rectangle rect1 = Rectangle(myentity->position.x, myentity->position.y, 150, 150);
	Rectangle rect2 = Rectangle(banaan->position.x, banaan->position.y, 150, 150);
	Rectangle rect3 = Rectangle(banaan2->position.x, banaan2->position.y, 150, 150);
	Rectangle rect4 = Rectangle(bom->position.x, bom->position.y, 150, 150);


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
		myentity->position = Point2(SWIDTH / 2, SHEIGHT / 1.2);
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

	//banaan1
 	if (Collider::rectangle2rectangle(rect1, rect2)) {
		this->removeChild(banaan);
	}
	else {
		banaan->line()->color = GREEN;
		myentity->line()->color = GREEN;
	}

	//banaan2
	if (Collider::rectangle2rectangle(rect1, rect3)) {
		this->removeChild(banaan2);
	}
	else {
		banaan2->line()->color = GREEN;
		myentity->line()->color = GREEN;
	}

	//bom
	if (Collider::rectangle2rectangle(rect1, rect4)) {
		this->removeChild(bom);
	}
	else {
		bom->line()->color = GREEN;
		myentity->line()->color = GREEN;
	}
}
