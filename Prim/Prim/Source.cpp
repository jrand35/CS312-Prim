#include "MyForm.h"
#include "Matrix.h"
using namespace Prim;
using namespace System;
using namespace System::Windows::Forms;
#include <iostream>

void LoadMatrix(Matrix*);

[STAThreadAttribute]
int main(cli::array<System::String^, 1>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm ^form = gcnew MyForm;
	Application::Run(form);

	return 0;

	Matrix *a = new Matrix(16, 16);
	LoadMatrix(a);
	//cout << a.Connect(0, 2, 10);


	cin.get();

	return 0;
}


//Works
void LoadMatrix(Matrix *m) {
	ifstream file;
	file.open("Small Graph.txt");
	if (file.fail()) {
		Application::Exit();
	}
	while (!file.eof()) {
		string n1, n2, w;
		file >> n1 >> n2 >> w;
		if (n1 != "" && n1 != "Vertex")
		{
			//cout << stoi(n1) << " " << stoi(n2) << " " << stoi(w) << endl;
			cout << m->Connect(stoi(n1), stoi(n2), stoi(w));
		}
	}
	file.close();
}