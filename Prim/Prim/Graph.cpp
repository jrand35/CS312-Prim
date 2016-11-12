#include "Graph.h"

Graph::Graph(int width, int height) {
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

Graph::~Graph() {
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

bool Graph::Connect(int node1, int node2, int weight) {
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

void Graph::Prim(int startVertex, int &blueVertex) {
	if (IsTreeComplete())
		return;
	//Starting the tree
	if (!tree[startVertex]) {
		tree[startVertex] = true;
	}
	int node1;
	int node2 = GetClosestNode(node1);

	if (node2 != -1) {
		PrimEdge(node1, node2);
		blueVertex = node2;
	}
}

bool Graph::IsTreeComplete() {
	bool complete = true;
	for (int i = 0; i < width; i++) {
		if (!tree[i])
			return false;
	}
	return true;
}

int Graph::GetClosestNode(int &node1) {
	int weight = 99999;
	int closestNode = -1;
	for (int node = 0; node < width; node++) {
		if (tree[node]) {
			for (int i = 0; i < width; i++) {
				if (node != i && data[node][i] < weight && data[node][i] != 0 && !IsPrim(node, i) && !tree[i]) {
					weight = data[node][i];
					closestNode = i;
					node1 = node;
				}
			}
		}
	}
	return closestNode;
}

bool Graph::PrimEdge(int node1, int node2) {

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

bool Graph::ConnectionExists(int node1, int node2) const {
	return (data[node1][node2] != 0 || data[node2][node1] != 0);
}

bool Graph::IsPrim(int node1, int node2) const {
	return (prim[node1][node2] || prim[node2][node1]);
}

bool Graph::InTree(int node) const {
	return (tree[node]);
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

Connection *Graph::GetConnection(int index) {
	return connectionList[index];
}

Connection *Graph::GetConnection(int node1, int node2) {
	for (int i = 0; i < connectionCount; i++) {
		if (connectionList[i]->Node1 == node1 && connectionList[i]->Node2 == node2) {
			return connectionList[i];
		}
	}

	return nullptr;
}

int Graph::ConnectionCount() const {
	return connectionCount;
}