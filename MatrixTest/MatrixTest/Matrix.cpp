#include "Matrix.h"

Matrix::Matrix(int width, int height) {
	this->width = width;
	this->height = height;
	data = new int*[width];
	for (int i = 0; i < height; i++) {
		data[i] = new int[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			data[i][j] = 0;
		}
	}

	data[10][5] = 5;
}

Matrix::~Matrix() {
	for (int i = 0; i < height; i++) {
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::Display() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

		}
	}
}