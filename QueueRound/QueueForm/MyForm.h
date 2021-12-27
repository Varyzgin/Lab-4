#pragma once
#include <msclr\marshal_cppstd.h>
#include "..\QueueRound\TQueue.h"
namespace QueueForm {

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
		int MaxSize, Size;
		double p, q;
		TQueue<int>* queue;
		Graphics^ gr;
		int CenterX, CenterY, Width, Height;
		TQueue<int>* tqueue;
		Random^ rnd;
		Pen^ BlackPen;
		Pen^ WhitePen;
		int PopCount;
		int PushCount;
	private: System::Windows::Forms::Button^ button2;
	private:
		Random^ rand;
	public:
		MyForm(void)
		{
			InitializeComponent();

			gr = CreateGraphics();
			rnd = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 9.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 9.0F;

			CenterX = 70;
			CenterY = 23;
			Width = Height = 80;

			PopCount = PushCount = 0;
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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(101, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"80";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 155);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"40";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(101, 181);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"0.8";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(101, 207);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"0.3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Макс. длина";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Исх. длина";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Р ( добавить )";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 210);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Р ( извлечь )";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(47, 263);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"В очереди";
			// 
			// timer1
			// 
			this->timer1->Interval = 400;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 233);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(123, 263);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"_";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(47, 285);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Добавилось";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(123, 285);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(47, 308);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(69, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Извлеклось";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(123, 308);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"0";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(116, 233);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 332);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->MinimumSize = System::Drawing::Size(240, 371);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);

		tqueue = new TQueue<int>(MaxSize);
		for (int i = 0; i < Size; i++) {
			tqueue->Push(i);
		}

		DrawQueue();
		timer1->Enabled = true;
	}

		   void DrawQueue() {
			   int start = 360 * tqueue->GetHead() / tqueue->GetMaxSize();
			   int finish = 360 * (tqueue->GetCount()) / tqueue->GetMaxSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		   }

		   void Clean() {
			   int start = 360 * tqueue->GetHead() / tqueue->GetMaxSize();
			   int finish = 360 * (tqueue->GetCount()) / tqueue->GetMaxSize();
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
		   }

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Clean();
		if (rnd->NextDouble() < p) {
			if (!tqueue->Full()) {
				tqueue->Push(1);
				PushCount++;
			}
		}
		if (rnd->NextDouble() < q) {
			if (!tqueue->Empty()) {
				tqueue->Pop();
				PopCount++;
			}
		}
		DrawQueue();
		label6->Text = Convert::ToString(tqueue->GetCount());
		label8->Text = Convert::ToString(PushCount);
		label10->Text = Convert::ToString(PopCount);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Clean();
		timer1->Enabled = false;
		tqueue->Clear();
		PushCount = 0;
		PopCount = 0;
		label6->Text = "_";
		label8->Text = Convert::ToString(PushCount);
		label10->Text = Convert::ToString(PopCount);
	}

};
}