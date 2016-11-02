#pragma once
class Matrix {
public:
	Matrix(int, int);
	~Matrix();
	void Display();
private:
	int **data;
	int width, height;
};