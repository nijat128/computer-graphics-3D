#include "Cube.hpp"

Cube::Cube()
{  
// your definition of cube vertices and faces

    r = 1.0; g = 0; b = 0;
}

void Cube::draw_face(int i)
{
// your drawing of face i
}

void Cube::drawMC()
{
	// replace the following by your cube drawing
	glColor3f(r, g, b);
	glutWireCube(1);
}

void Cube::draw()
{
    glPushMatrix();
    this->ctmMultiply();
	glScalef(s, s, s);
	drawMC();
    glPopMatrix();
}
