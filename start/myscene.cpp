#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	srand(time(nullptr));

	scoretext = new Text();
	scoretext->position.x = 50;
	scoretext->position.y = 75;
	score = 0;

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.   
	myentity = new MyEntity();
	myentity->position = Point2(640, 600);

	background = new Background();
	background->position = Point2(640, 360);
	background->scale = Point2(1.25f, 1.4f);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(myentity);
	this->addChild(scoretext);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(background);
	this->removeChild(scoretext);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete background;
	delete scoretext;
}

void MyScene::update(float deltaTime)
{
	if (t.seconds() > 1.0f) {
		for (size_t i = 0; i < lanes.size(); i++) {
			Pickup* pickup = new Pickup();
			pickup->position = Point2(lanes[i], -200);
			if (pickup->r != 3) {
				pickups.push_back(pickup);
				this->addChild(pickup);
			}
			t.start();
		}
	}

	if (input()->getKeyUp(KeyCode::Space)) { //plant poop
		myentity->scale = Point(1.0f, 1.0f);
	}

	if (input()->getKeyUp(KeyCode::Escape)) { //stop game
		this->stop();
	}


	if (input()->getKeyDown(KeyCode::S)) { //middle lane
		myentity->position = Point2(640, 600);
	}

	if (input()->getKeyDown(KeyCode::A)) { //left lane
		myentity->position = Point2(215, 600);
	}

	if (input()->getKeyDown(KeyCode::D)) { //right lane
		myentity->position = Point2(1065, 600);
	}


	Rectangle rect1 = Rectangle(myentity->position.x, myentity->position.y, 150, 150);

	for (size_t i = 0; i < pickups.size(); i++) {
		std::cout << ": " << i << std::endl;
		//std::cout << pickups[i]->position.y << " ";
		Rectangle rect2 = Rectangle(pickups[i]->position.x, pickups[i]->position.y, 150, 150);
		if (Collider::rectangle2rectangle(rect1, rect2)) {
			this->removeChild(pickups[i]);
			delete pickups[i];
			pickups.erase(pickups.begin() + i);
			score++;
		}
	}
	if (input()->getKeyDown(KeyCode::Space)) { //plant poop
		myentity->scale = Point(0.8f, 0.8f);
		poop = new Poop();
		poop->position = myentity->position;
		this->addChild(poop);
		if (Collider::rectangle2rectangle(rect1, rect1)) {
		}
	}
	

	std::string st = "Score: ";
	st += std::to_string(score);
	scoretext->message(st);

	// std:: cout<< std::endl;


}
