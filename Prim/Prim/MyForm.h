#pragma once

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
				for (int i = 0; i < ARRAY_SIZE; i++) {
					delete nodes[i];
					delete[] connectionMatrix[i];
				}
				delete[] connectionMatrix;
				//Deleting connectionMatrix properly?
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

		int **InitializeConnectionMatrix(){
			int **matrix = new int*[ARRAY_SIZE];
			for (int i = 0; i < ARRAY_SIZE; i++){
				(matrix)[i] = new int[ARRAY_SIZE];
				for (int j = 0; j < ARRAY_SIZE; j++){
					(matrix)[i][j] = 0;
				}
			}
			return matrix;
		}

		//May not be necessary...
		void Connection(int *matrix[], int x, int y, int value){
			matrix[x][y] = value;
			matrix[y][x] = value;
		}

		//array<Rectangle*>^ nodes;
		array<Label^>^ nodes;
		Graphics ^g;
		SolidBrush ^b;
		Pen ^normalPen;
		Pen ^spanPen;
		int **connectionMatrix;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		//nodes = gcnew array<Rectangle*>(ARRAY_SIZE);
		nodes = gcnew array<Label^>(ARRAY_SIZE);
		g = panel1->CreateGraphics();
		b = gcnew SolidBrush(Color::Blue);
		normalPen = gcnew Pen(Color::LightBlue);
		connectionMatrix = InitializeConnectionMatrix();
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

		Connection(connectionMatrix, 0, 2, 10);
		Connection(connectionMatrix, 0, 6, 8);
		Connection(connectionMatrix, 0, 4, 6);
		Connection(connectionMatrix, 0, 7, 12);

		Connection(connectionMatrix, 1, 2, 8);
		Connection(connectionMatrix, 1, 3, 9);
		Connection(connectionMatrix, 1, 5, 10);

		Connection(connectionMatrix, 2, 3, 6);
		Connection(connectionMatrix, 2, 1, 8);
		Connection(connectionMatrix, 2, 0, 10);
		Connection(connectionMatrix, 2, 6, 5);
		Connection(connectionMatrix, 2, 8, 7);

		Connection(connectionMatrix, 3, 1, 9);
		Connection(connectionMatrix, 3, 2, 6);
		Connection(connectionMatrix, 3, 9, 9);

		Connection(connectionMatrix, 4, 5, 14);
		Connection(connectionMatrix, 4, 7, 7);
		Connection(connectionMatrix, 4, 0, 6);

		Connection(connectionMatrix, 5, 4, 14);
		Connection(connectionMatrix, 5, 7, 16);
		Connection(connectionMatrix, 5, 1, 10);

		Connection(connectionMatrix, 6, 2, 5);
		Connection(connectionMatrix, 6, 0, 8);

		Connection(connectionMatrix, 7, 5, 16);
		Connection(connectionMatrix, 7, 0, 12);
		Connection(connectionMatrix, 7, 4, 7);

		Connection(connectionMatrix, 8, 2, 7);
		Connection(connectionMatrix, 8, 10, 10);

		Connection(connectionMatrix, 9, 3, 9);
		Connection(connectionMatrix, 9, 12, 10);

		Connection(connectionMatrix, 10, 8, 10);
		Connection(connectionMatrix, 10, 12, 16);
		Connection(connectionMatrix, 10, 14, 7);
		Connection(connectionMatrix, 10, 15, 6);

		Connection(connectionMatrix, 11, 12, 8);

		Connection(connectionMatrix, 12, 11, 8);
		Connection(connectionMatrix, 12, 9, 10);
		Connection(connectionMatrix, 12, 10, 16);

		Connection(connectionMatrix, 14, 10, 7);
		Connection(connectionMatrix, 14, 15, 6);

		Connection(connectionMatrix, 15, 10, 9);
		Connection(connectionMatrix, 15, 14, 6);
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//g->FillEllipse(b, 0, 0, 10, 10);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < ARRAY_SIZE; j++){
				if (connectionMatrix[i][j] > 0){
					Label ^s = nodes[i];
					Label ^e = nodes[j];
					g->DrawLine(normalPen, s->Location.X + 16, s->Location.Y + 16, e->Location.X + 16, e->Location.Y + 16);
				}
			}
		}
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
