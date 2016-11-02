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
}

Matrix::~Matrix() {
	for (int i = 0; i < height; i++) {
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::Display() {
	for (int i = 0; i < height; i++) {
		for (int j = width - 1; j >= 0; j--) {
			std::cout << data[j][i] << " ";
		}
		std::cout << std::endl;
	}
}