#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLfloat r, g, b;

public:
	Cube();
	void draw();
	void drawMC();

private:
	void draw_face(int);
};

#endif
