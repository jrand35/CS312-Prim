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

	private: System::Windows::Forms::TextBox^  node2box;
	private: System::Windows::Forms::TextBox^  node1box;
	private: System::Windows::Forms::Label^  errorlabel;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  StartVertex;
	private: System::Windows::Forms::Button^  PrimButton;
	private: System::Windows::Forms::Label^  label3;




	protected:
	private: System::Windows::Forms::Panel^  panel1;



	protected:
	private:

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
					bool result = m->Connect(stoi(n1), stoi(n2), stoi(w));
					if (!result) {
						
					}
				}
			}
			file.close();
		}

		bool TryPrim(int node1, int node2, int weight, String ^&message) {
			if (node1 < 0 || node1 > ARRAY_SIZE - 1) {
				message = "Invalid index for node 1";
				return false;
			}
			else if (node2 < 0 || node2 > ARRAY_SIZE - 1) {
				message = "Invalid index for node 2";
				return false;
			}
			else if (node1 == node2) {
				message = "Cannot connect to the same node";
				return false;
			}
			else if (!connectionMatrix->ConnectionExists(node1, node2)) {
				message = "These nodes are not connected";
				return false;
			}
			else if (connectionMatrix->IsPrim(node1, node2)) {
				message = "Prim connection already exists";
				return false;
			}
			else if (weight <= 0) {
				message = "Weight cannot be 0";
				return false;
			}
			connectionMatrix->PrimEdge(node1, node2);
			message = "Success";

			SetBlueLabel(nodes[node1]);
			SetBlueLabel(nodes[node2]);
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

		Label^ newLabel2(System::String^ text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::Transparent;
			l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(16, 16);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}

		void SetBlueLabel(Label ^label) {
			label->BackColor = System::Drawing::Color::Blue;
			label->ForeColor = System::Drawing::Color::White;
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->PrimButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->StartVertex = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->errorlabel = (gcnew System::Windows::Forms::Label());
			this->node2box = (gcnew System::Windows::Forms::TextBox());
			this->node1box = (gcnew System::Windows::Forms::TextBox());
			this->connectbutton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->PrimButton);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->StartVertex);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->errorlabel);
			this->panel1->Controls->Add(this->node2box);
			this->panel1->Controls->Add(this->node1box);
			this->panel1->Controls->Add(this->connectbutton);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(560, 538);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(381, 240);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Starting node";
			// 
			// PrimButton
			// 
			this->PrimButton->Location = System::Drawing::Point(482, 263);
			this->PrimButton->Name = L"PrimButton";
			this->PrimButton->Size = System::Drawing::Size(75, 23);
			this->PrimButton->TabIndex = 10;
			this->PrimButton->Text = L"Prim";
			this->PrimButton->UseVisualStyleBackColor = true;
			this->PrimButton->Click += gcnew System::EventHandler(this, &MyForm::PrimButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(418, 217);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Run Prim\'s Algorithm";
			// 
			// StartVertex
			// 
			this->StartVertex->Location = System::Drawing::Point(457, 237);
			this->StartVertex->Name = L"StartVertex";
			this->StartVertex->Size = System::Drawing::Size(100, 20);
			this->StartVertex->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(432, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Manually add edge";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(409, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Node 2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(409, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Node 1";
			// 
			// errorlabel
			// 
			this->errorlabel->AutoSize = true;
			this->errorlabel->Location = System::Drawing::Point(231, 13);
			this->errorlabel->Name = L"errorlabel";
			this->errorlabel->Size = System::Drawing::Size(28, 13);
			this->errorlabel->TabIndex = 4;
			this->errorlabel->Text = L"error";
			this->errorlabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// node2box
			// 
			this->node2box->Location = System::Drawing::Point(457, 96);
			this->node2box->Name = L"node2box";
			this->node2box->Size = System::Drawing::Size(100, 20);
			this->node2box->TabIndex = 2;
			// 
			// node1box
			// 
			this->node1box->Location = System::Drawing::Point(457, 70);
			this->node1box->Name = L"node1box";
			this->node1box->Size = System::Drawing::Size(100, 20);
			this->node1box->TabIndex = 1;
			// 
			// connectbutton
			// 
			this->connectbutton->Location = System::Drawing::Point(482, 122);
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
			this->Text = L"Prim\'s Algorithm";
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
		Matrix *connectionMatrix = nullptr;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		errorlabel->Text = "";
		connectionMatrix = new Matrix(ARRAY_SIZE, ARRAY_SIZE);
		LoadMatrix(connectionMatrix);
		//nodes = gcnew array<Rectangle*>(ARRAY_SIZE);
		nodes = gcnew cli::array<Label^, 1>(ARRAY_SIZE);
		g = panel1->CreateGraphics();
		b = gcnew SolidBrush(Color::Blue);
		normalPen = gcnew Pen(Color::LightBlue);
		spanPen = gcnew Pen(Color::Blue);

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

		//Add weights
		for (int i = 0; i < connectionMatrix->ConnectionCount(); i++){
			Connection *c = connectionMatrix->GetConnection(i);
			Point node1 = nodes[c->Node1]->Location;
			Point node2 = nodes[c->Node2]->Location;
			Point center = Point(node1.X + (node2.X - node1.X) / 2, node1.Y + (node2.Y - node1.Y) / 2);
			newLabel2(c->Weight.ToString(), center.X + 8, center.Y + 8);
		}

	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//g->FillEllipse(b, 0, 0, 10, 10);
		//for (int i = 0; i < ARRAY_SIZE; i++) {
		//	for (int j = 0; j < ARRAY_SIZE; j++){
		//		//if (connectionMatrix[i][j] > 0){
		//		//	Label ^s = nodes[i];
		//		//	Label ^e = nodes[j];
		//		//	g->DrawLine(normalPen, s->Location.X + 16, s->Location.Y + 16, e->Location.X + 16, e->Location.Y + 16);
		//		//}
		//	}
		//}

		//Draw each connection
		//For loop currently causing issues
		for (int i = 0; i < connectionMatrix->ConnectionCount(); i++) {
			Connection *c = connectionMatrix->GetConnection(i);
			Label ^s = nodes[c->Node1];
			Label ^e = nodes[c->Node2];
			int weight = c->Weight;
			if (connectionMatrix->IsPrim(c->Node1, c->Node2))
				g->DrawLine(spanPen, s->Location.X + 16, s->Location.Y + 16, e->Location.X + 16, e->Location.Y + 16);
			else
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
	//int weight = (weightbox->Text == "") ? -1 : int::Parse(weightbox->Text);

	if (node1 == -1 || node2 == -1) {
		errorlabel->Text = "Error: Node index must not be empty";
		panel1->Refresh();
		return;
	}

	String ^message = gcnew String("");
	bool success = TryPrim(node1, node2, 5, message);
	if (!success) {
		errorlabel->Text = "Error: " + message;
	}
	else {
		errorlabel->Text = "";
		panel1->Refresh();
	}
}
private: System::Void PrimButton_Click(System::Object^  sender, System::EventArgs^  e) {
	int vertex = (StartVertex->Text == "") ? -1 : int::Parse(StartVertex->Text);
	int blueNode = -1;
	if (!connectionMatrix->InTree(vertex))
		SetBlueLabel(nodes[vertex]);
	connectionMatrix->Prim(vertex, blueNode);
	if (blueNode != -1)
		SetBlueLabel(nodes[blueNode]);
	panel1->Refresh();
}
};
}
