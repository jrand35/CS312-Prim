#pragma once
#include <iostream>
class Matrix {
public:
	Matrix(int, int);
	~Matrix();
	void Display();
private:
	int **data;
	int width, height;
};