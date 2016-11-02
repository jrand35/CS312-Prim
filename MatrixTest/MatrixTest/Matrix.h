#pragma once
#include <iostream>
#include <list>
#include "Connection.h"
using namespace std;
class Matrix {
public:
	Matrix(int, int);
	~Matrix();
	void Display() const;
	bool Connect(int, int, int);
	void SetBeginning();
	bool AtEnd();
	Connection GetConnection();
private:
	list<Connection> connectionList;
	list<Connection>::iterator it;
	bool *tree;
	int **data;
	int width, height;
};