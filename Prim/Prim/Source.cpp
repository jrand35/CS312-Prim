#include "MyForm.h"
#include "Graph.h"
using namespace Prim;
using namespace System;
using namespace System::Windows::Forms;
#include <iostream>

void LoadGraph(Graph*);

[STAThreadAttribute]
int main(cli::array<System::String^, 1>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm ^form = gcnew MyForm;
	Application::Run(form);

	return 0;

	Graph *g = new Graph(16, 16);
	LoadGraph(g);
	//cout << a.Connect(0, 2, 10);


	cin.get();

	return 0;
}


//Works
void LoadGraph(Graph *m) {
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