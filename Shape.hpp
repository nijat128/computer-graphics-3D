/**
 *	file Shape.hpp
 *	description: header of Matrix class
 *
 */

#ifndef CSHAPE_H
#define CSHAPE_H

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace std;

/**
 * Shape class the common class that will be inherited model object class
 */
class Shape {
protected:
	Matrix mc; // the Model coordinate system (X, Y, Z, 0) in WC, represent the position of the object in WC
	GLfloat s; // scale factor

public:
	Shape();           // constructor
	virtual ~Shape();  // destructor
	Matrix getMC();    // Matrix
	void ctmMultiply();    // function to do the CTM * MC
	void scaleChange(GLfloat x); // to change the scale factor
	void translate(GLfloat tx, GLfloat ty, GLfloat tz); //translate the MC origin
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);      // rotate object in WC
	void rotateOrigin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);// just rotate the origin of object in WC
	void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);    // to rotate in MC
	void reset();   // a function that resets the shape transformation matrix
	virtual void draw() = 0; // draw function must be overwritten

};

#endif
