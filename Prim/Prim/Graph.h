#pragma once
#include "Connection.h"
#include "PtrArray.h"
using namespace std;
using namespace System::Collections::Generic;

class Graph {
public:
	Graph(int, int);
	~Graph();
	//void Display() const;
	bool Connect(int, int, int);
	void Prim(int, int &);
	bool PrimEdge(int, int);
	bool ConnectionExists(int, int) const;
	bool IsPrim(int, int) const;
	bool InTree(int) const;
	//void SetBeginning();
	//bool AtEnd() const;
	Connection *GetConnection(int);
	int ConnectionCount() const;
private:
	Connection *GetConnection(int, int);
	int GetClosestNode(int &);
	bool IsTreeComplete();
	//PtrArray<Connection> connectionList;
	Connection connectionList[100];
	//list<Connection> connectionList;
	//list<Connection>::iterator it;
	bool *tree;
	bool **prim;
	int **data;
	int width, height;
	int connectionCount;
};