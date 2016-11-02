#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"
using namespace std;

int main() {
	Matrix desmond(16, 16);

	ifstream file;
	file.open("Small Graph.txt");
	while (!file.eof()) {
		string n1, n2, w;
		file >> n1 >> n2 >> w;
		if (n1 != "" && n1 != "Vertex")
		{
			desmond.Connect(stoi(n1), stoi(n2), stoi(w));
		}
	}
	file.close();

	desmond.Display();
	cout << desmond.ConnectionCount();

	cin.get();
	return 0;
}