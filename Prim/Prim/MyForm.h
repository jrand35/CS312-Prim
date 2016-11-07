#pragma once
#include "Matrix.h"
#include <fstream>
#include <string>

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
			delete connectionMatrix;
		}
	private: System::Windows::Forms::Button^  connectbutton;
	protected:
	private: System::Windows::Forms::TextBox^  weightbox;
	private: System::Windows::Forms::TextBox^  node2box;
	private: System::Windows::Forms::TextBox^  node1box;
	private: System::Windows::Forms::Label^  errorlabel;


	protected:
	private: System::Windows::Forms::Panel^  panel1;



	protected:
	private:

		void LoadMatrix(Matrix &m) {
			ifstream file;
			file.open("Small Graph.txt");
			if (file.fail()) {
				return;
			}
			while (!file.eof()) {
				string n1, n2, w;
				file >> n1 >> n2 >> w;
				if (n1 != "" && n1 != "Vertex")
				{
					m.Connect(stoi(n1), stoi(n2), stoi(w));
				}
			}
			file.close();
		}

		bool CheckValidConnection(int node1, int node2, int weight, String ^&message) {
			if (node1 < 0 || node1 > ARRAY_SIZE - 1) {
				message = "Invalid index for node 1";
				return false;
			}
			else if (node2 < 0 || node2 > ARRAY_SIZE - 1) {
				message = "Invalid index for node 2";
				return false;
			}
			else if (connectionMatrix->ConnectionExists(node1, node2)) {
				message = "Connection already exists";
				return false;
			}
			else if (weight <= 0) {
				message = "Weight cannot be 0";
				return false;
			}
			connectionMatrix->Connect(node1, node2, weight);
			message = "Success";
			return true;
		}

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
			this->errorlabel = (gcnew System::Windows::Forms::Label());
			this->weightbox = (gcnew System::Windows::Forms::TextBox());
			this->node2box = (gcnew System::Windows::Forms::TextBox());
			this->node1box = (gcnew System::Windows::Forms::TextBox());
			this->connectbutton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->errorlabel);
			this->panel1->Controls->Add(this->weightbox);
			this->panel1->Controls->Add(this->node2box);
			this->panel1->Controls->Add(this->node1box);
			this->panel1->Controls->Add(this->connectbutton);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(560, 538);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// errorlabel
			// 
			this->errorlabel->AutoSize = true;
			this->errorlabel->Location = System::Drawing::Point(454, 143);
			this->errorlabel->Name = L"errorlabel";
			this->errorlabel->Size = System::Drawing::Size(28, 13);
			this->errorlabel->TabIndex = 4;
			this->errorlabel->Text = L"error";
			this->errorlabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// weightbox
			// 
			this->weightbox->Location = System::Drawing::Point(457, 91);
			this->weightbox->Name = L"weightbox";
			this->weightbox->Size = System::Drawing::Size(100, 20);
			this->weightbox->TabIndex = 3;
			// 
			// node2box
			// 
			this->node2box->Location = System::Drawing::Point(457, 65);
			this->node2box->Name = L"node2box";
			this->node2box->Size = System::Drawing::Size(100, 20);
			this->node2box->TabIndex = 2;
			// 
			// node1box
			// 
			this->node1box->Location = System::Drawing::Point(457, 39);
			this->node1box->Name = L"node1box";
			this->node1box->Size = System::Drawing::Size(100, 20);
			this->node1box->TabIndex = 1;
			// 
			// connectbutton
			// 
			this->connectbutton->Location = System::Drawing::Point(482, 117);
			this->connectbutton->Name = L"connectbutton";
			this->connectbutton->Size = System::Drawing::Size(75, 23);
			this->connectbutton->TabIndex = 0;
			this->connectbutton->Text = L"Connect";
			this->connectbutton->UseVisualStyleBackColor = true;
			this->connectbutton->Click += gcnew System::EventHandler(this, &MyForm::connectbutton_Click);
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
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		//array<Rectangle*>^ nodes;
		cli::array<Label^>^ nodes;
		Graphics ^g;
		SolidBrush ^b;
		Pen ^normalPen;
		Pen ^spanPen;
		Matrix *connectionMatrix;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		connectionMatrix = new Matrix(16, 16);
		LoadMatrix(*connectionMatrix);
		//nodes = gcnew array<Rectangle*>(ARRAY_SIZE);
		nodes = gcnew cli::array<Label^, 1>(ARRAY_SIZE);
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

		//Draw each connection
		for (int i = 0; i < connectionMatrix->ConnectionCount(); i++) {
			Connection *c = connectionMatrix->GetConnection(i);
			Label ^s = nodes[c->Node1];
			Label ^e = nodes[c->Node2];
			int weight = c->Weight;
			g->DrawLine(normalPen, s->Location.X + 16, s->Location.Y + 16, e->Location.X + 16, e->Location.Y + 16);
		}
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void connectbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	//int node1 = Convert::ToInt32(node1box->Text);
	//int node2 = Convert::ToInt32(node2box->Text);
	//int weight = Convert::ToInt32(weightbox->Text);
	int node1 = (node1box->Text == "") ? -1 : int::Parse(node1box->Text);
	int node2 = (node2box->Text == "") ? -1 : int::Parse(node2box->Text);
	int weight = (weightbox->Text == "") ? -1 : int::Parse(weightbox->Text);

	String ^message = gcnew String("");
	bool success = CheckValidConnection(node1, node2, weight, message);
	if (!success) {
		errorlabel->Text = message;
	}
	else {
		errorlabel->Text = "";
		panel1->Refresh();
	}
}
};
}
