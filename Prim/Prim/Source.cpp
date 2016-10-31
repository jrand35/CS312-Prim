#include "MyForm.h"
using namespace Prim;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm ^form = gcnew MyForm;
	Application::Run(form);
	return 0;
}