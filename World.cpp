/**
 * File: World.hpp
 */

#include "World.hpp"

World::World() {
	objnum = 3; // number of object
	list[0] = (Shape*) malloc( sizeof(Shape*) * objnum);  // array to hold object pointers

	//cube object
	list[0] = new Cube();

	//Pyramid, replace the following by your pyramid
	list[1] = new Cube();
	list[1]->scaleChange(-0.5);
	list[1]->translate(0, -2, 0);

	//house, replace the following by your house
	list[2] = new Cube();
	list[2]->scaleChange(-0.2);
	list[2]->translate(0.5, 0, 3);

}

World::~World(){
	for (int i = 0; i<objnum; i++)
	   delete list[i];

	free(list);
}

void World::draw() {
	for (int i = 0; i<objnum; i++)
	   list[i]->draw();
}

void World::reset() {
	for (int i = 0; i<objnum; i++)
	   list[i]->reset();
}

