/**
 *	CP411A2 reference design
 *	author: HBF
 *	date: 2019/09/29
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Menu.hpp"

// gloable variables
GLint winWidth = 800, winHeight = 800;
GLint xbegin = 0;     // x coordinate of mouse clik
GLint coordinate = 1; // coordinate system selection : 1 for MC, 2 for WC, 3 for CV
GLint option = 4;     // transform option
GLint objIndex;       // index of selected object

GLint move = 0;


World myWorld;
Camera myCamera;

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("A2 reference design (HBF)");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	myCamera.setProjectionMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.draw();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseAction(int button, int action, int x, int y) {
	if (button == GLUT_LEFT_BUTTON ) {
		if (action == GLUT_DOWN) {
		   move = 1;
	       xbegin = x;
	    } else if (action == GLUT_UP) {
	    	move = 0;
     	}
	}
}

void mouseMotion(GLint x, GLint y) {
	GLfloat rx, ry, rz, theta;
	Shape *sshapep = NULL;
	sshapep = myWorld.list[objIndex];

	if (move) {

		if (coordinate == 1 && option == 1) {
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = sshapep->getMC().mat[0][0];
			ry = sshapep->getMC().mat[1][0];
			rz = sshapep->getMC().mat[2][0];
			sshapep->rotateMC(rx, ry, rz, theta * 0.5);
		}

		else if (coordinate == 1 && option == 2) {
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = sshapep->getMC().mat[0][1];
			ry = sshapep->getMC().mat[1][1];
			rz = sshapep->getMC().mat[2][1];
			sshapep->rotate(rx, ry, rz, theta * 0.5);
		}

		else if (coordinate == 2 && option == 1) {
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 1;
			ry = 0;
			rz = 0;
			sshapep->rotateOrigin(rx, ry, rz, theta * 0.5);
		}

		else if (coordinate == 2 && option == 2) {
			theta = (xbegin - x > 0) ? 1 : -1;
			rx = 0;
			ry = 1;
			rz = 0;
			sshapep->rotateOrigin(rx, ry, rz, theta * 0.5);
		}

		else if (coordinate == 1 && option == 4) {
			theta = (xbegin - x < 0) ? 1 : -1;
			sshapep->scaleChange(theta * 0.02);
		}

		else if (coordinate == 2 && option == 4) {
			theta = (xbegin - x < 0) ? 1 : -1;
			sshapep->translate(theta * 0.02, 0, 0);
		}

		// add more
		glutPostRedisplay();
	}

}

int main(int argc, char** argv) {
	  setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	  setvbuf(stderr, NULL, _IONBF, 0);
	//	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);
	menu();
	init();
	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

