#include "Matrix.h"

Matrix::Matrix(int width, int height) {
	connectionCount = 0;
	this->width = width;
	this->height = height;
	tree = new bool[width];
	prim = new bool*[width];
	for (int i = 0; i < width; i++) {
		tree[i] = false;
	}
	data = new int*[width];
	for (int i = 0; i < height; i++) {
		data[i] = new int[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			data[i][j] = 0;
		}
	}
	for (int i = 0; i < height; i++) {
		prim[i] = new bool[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			prim[i][j] = false;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < height; i++) {
		delete[] data[i];
	}
	delete[] data;
	delete[] tree;
	for (int i = 0; i < height; i++) {
		delete[] prim[i];
	}
	delete[] prim;
}

//void Matrix::Display() const {
//	cout << "   ";
//	for (int i = 0; i < width; i++) {
//		cout << i << " " << ((i > 9) ? "" : " ");
//	}
//	cout << endl;
//
//	for (int i = 0; i < height; i++) {
//		cout << i << " " << ((i > 9) ? "" : " ");
//		for (int j = 0; j < width; j++) {
//			cout << data[j][i] << " " << ((data[j][i] > 9) ? "" : " ");
//		}
//		cout << std::endl;
//	}
//}

bool Matrix::Connect(int node1, int node2, int weight) {
	if (data[node1][node2] != 0 || data[node2][node1] != 0)
		return false;
	data[node1][node2] = weight;
	data[node2][node1] = weight;
	Connection *c = new Connection;
	c->Node1 = node1;
	c->Node2 = node2;
	c->Weight = weight;
	connectionList.Add(*c);

	//if (!tree[node1])
	//	tree[node1] = true;
	//if (!tree[node2])
	//	tree[node2] = true;

	connectionCount++;
	return true;
}

bool Matrix::Prim(int node1, int node2) {

	if (data[node1][node2] == 0 || data[node2][node1] == 0) {
		return false;
	}

	prim[node1][node2] = true;
	prim[node2][node1] = true;

	if (!tree[node1])
		tree[node1] = true;
	if (!tree[node2])
		tree[node2] = true;
	return true;
}

bool Matrix::ConnectionExists(int node1, int node2) const {
	return (data[node1][node2] != 0 || data[node2][node1] != 0);
}

bool Matrix::IsPrim(int node1, int node2) const {
	return (prim[node1][node2] || prim[node2][node1]);
}

//void Matrix::SetBeginning() {
//	it = connectionList.begin();
//}

//bool Matrix::AtEnd() const {
//	return (it == connectionList.end());
//}

//Connection Matrix::GetConnection() {
//	Connection c = *it;
//	++it;
//	return c;
//}

Connection *Matrix::GetConnection(int index) {
	return connectionList[index];
}

Connection *Matrix::GetConnection(int node1, int node2) {
	for (int i = 0; i < connectionCount; i++) {
		if (connectionList[i]->Node1 == node1 && connectionList[i]->Node2 == node2) {
			return connectionList[i];
		}
	}

	return nullptr;
}

int Matrix::ConnectionCount() const {
	return connectionCount;
}