#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	Matrix desmond(16, 16);
	desmond.Connect(4, 10, 1);
	desmond.Connect(5, 11, 2);
	desmond.Connect(6, 12, 3);
	desmond.Connect(6, 12, 3);
	desmond.Connect(12, 6, 3);
	desmond.Display();

	desmond.SetBeginning();

	while (!desmond.AtEnd()) {
		cout << desmond.GetConnection().Weight;
	}

	cin.get();
	return 0;
}