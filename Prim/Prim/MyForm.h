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
				}
			}
		}
	private: System::Windows::Forms::Panel^  panel1;


	protected:

	private:
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

		array<Rectangle*>^ nodes;
		Graphics ^g;
		SolidBrush ^b;
		Pen ^p;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		nodes = gcnew array<Rectangle*>(ARRAY_SIZE);
		g = panel1->CreateGraphics();
		b = gcnew SolidBrush(Color::Blue);
		p = gcnew Pen(Color::Blue);

		nodes[0] = new Rectangle(0, 0, 20, 20);
		nodes[1] = new Rectangle(0, 0, 20, 20);
		nodes[2] = new Rectangle(0, 0, 20, 20);
		nodes[3] = new Rectangle(0, 0, 20, 20);
		nodes[4] = new Rectangle(0, 0, 20, 20);
		nodes[5] = new Rectangle(0, 0, 20, 20);
		nodes[6] = new Rectangle(0, 0, 20, 20);
		nodes[7] = new Rectangle(0, 0, 20, 20);
		nodes[8] = new Rectangle(0, 0, 20, 20);
		nodes[9] = new Rectangle(0, 0, 20, 20);
		nodes[10] = new Rectangle(0, 0, 20, 20);
		nodes[11] = new Rectangle(0, 0, 20, 20);
		nodes[12] = new Rectangle(0, 0, 20, 20);
		nodes[13] = new Rectangle(0, 0, 20, 20);
		nodes[14] = new Rectangle(0, 0, 20, 20);
		nodes[15] = new Rectangle(0, 0, 20, 20);
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//g->FillEllipse(b, 0, 0, 10, 10);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			g->FillEllipse(b, *nodes[i]);
		}
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
