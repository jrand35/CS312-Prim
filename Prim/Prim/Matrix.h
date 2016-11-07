#pragma once
#include "Connection.h"
#include "PtrArray.h"
using namespace std;
using namespace System::Collections::Generic;

class Matrix {
public:
	Matrix(int, int);
	~Matrix();
	//void Display() const;
	bool Connect(int, int, int);
	//void SetBeginning();
	//bool AtEnd() const;
	Connection *GetConnection(int);
	int ConnectionCount() const;
private:
	PtrArray<Connection> connectionList;
	//list<Connection> connectionList;
	//list<Connection>::iterator it;
	bool *tree;
	int **data;
	int width, height;
	int connectionCount;
};