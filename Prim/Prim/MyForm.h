#pragma once
using namespace std;

const int ARRAY_SIZE = 16;

namespace Prim {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;



	protected:
	private:

		Label^ newLabel(System::String ^text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::LightBlue;
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(32, 32);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(560, 538);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 562);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		//array<Rectangle*>^ nodes;
		array<Label^>^ nodes;
		Graphics ^g;
		SolidBrush ^b;
		Pen ^normalPen;
		Pen ^spanPen;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		//nodes = gcnew array<Rectangle*>(ARRAY_SIZE);
		nodes = gcnew array<Label^>(ARRAY_SIZE);
		g = panel1->CreateGraphics();
		b = gcnew SolidBrush(Color::Blue);
		normalPen = gcnew Pen(Color::LightBlue);
		//Scatter the nodes in random places around the panel
		nodes[0] = newLabel("0", 40, 10);
		nodes[1] = newLabel("1", 0, 150);
		nodes[2] = newLabel("2", 50, 80);
		nodes[3] = newLabel("3", 450, 160);
		nodes[4] = newLabel("4", 140, 270);
		nodes[5] = newLabel("5", 190, 130);
		nodes[6] = newLabel("6", 450, 10);
		nodes[7] = newLabel("7", 10, 300);
		nodes[8] = newLabel("8", 270, 200);
		nodes[9] = newLabel("9", 320, 250);
		nodes[10] = newLabel("10", 120, 400);
		nodes[11] = newLabel("11", 90, 225);
		nodes[12] = newLabel("12", 480, 490);
		nodes[13] = newLabel("13", 400, 110);
		nodes[14] = newLabel("14", 270, 105);
		nodes[15] = newLabel("15", 160, 80);

	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//g->FillEllipse(b, 0, 0, 10, 10);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < ARRAY_SIZE; j++){
				//if (connectionMatrix[i][j] > 0){
				//	Label ^s = nodes[i];
				//	Label ^e = nodes[j];
				//	g->DrawLine(normalPen, s->Location.X + 16, s->Location.Y + 16, e->Location.X + 16, e->Location.Y + 16);
				//}
			}
		}
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
