/**
 *	File Matrix.cpp
 *	Description: implementation of Matrix class
 *
 */

#include "Matrix.hpp"

// mat <- identity matrix
Matrix::Matrix() {
	loadIdentity();
}

void Matrix::loadIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

// multiplication  mat <- m * mat
void Matrix::matrixPreMultiply(Matrix* m) {
	GLfloat temp[4][4], sum=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum = 0;
			for (int k = 0; k < 4; k++) {
				sum += m->mat[i][k] * mat[k][j];
			}
			temp[i][j] = sum;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}

// transpose  mat <- mat'
void Matrix::transpose() {
// your implementation
}

// normalize mat
void Matrix::normalize() {
// your implementaiton
}

// v  <- mat * v
void Matrix::multiplyVector(GLfloat *v) {
// your implementaiton
}

// mat <- rotation matrix (rx, ry, rz, angle)
void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
// your implementaiton
}

