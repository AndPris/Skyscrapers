#pragma once
#include "Solver.h"
#include "Puzzle.h"

namespace Skyscrapers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Welcome
	/// </summary>
	public ref class Welcome : public System::Windows::Forms::Form
	{
	public:
		Welcome(void)
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
		~Welcome()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ size;
	private: System::Windows::Forms::Button^ program_solver_btn;
	private: System::Windows::Forms::Button^ show_rules_btn;
	private: System::Windows::Forms::Button^ hand_solver_btn;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->size = (gcnew System::Windows::Forms::NumericUpDown());
			this->program_solver_btn = (gcnew System::Windows::Forms::Button());
			this->show_rules_btn = (gcnew System::Windows::Forms::Button());
			this->hand_solver_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->size))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Розмір головоломки";
			// 
			// size
			// 
			this->size->Location = System::Drawing::Point(157, 69);
			this->size->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->size->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->size->Name = L"size";
			this->size->Size = System::Drawing::Size(120, 22);
			this->size->TabIndex = 1;
			this->size->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// program_solver_btn
			// 
			this->program_solver_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->program_solver_btn->Location = System::Drawing::Point(89, 127);
			this->program_solver_btn->Name = L"program_solver_btn";
			this->program_solver_btn->Size = System::Drawing::Size(149, 67);
			this->program_solver_btn->TabIndex = 2;
			this->program_solver_btn->Text = L"Програмне розв\'язання";
			this->program_solver_btn->UseVisualStyleBackColor = true;
			this->program_solver_btn->Click += gcnew System::EventHandler(this, &Welcome::program_solver_btn_Click);
			// 
			// show_rules_btn
			// 
			this->show_rules_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->show_rules_btn->Location = System::Drawing::Point(89, 273);
			this->show_rules_btn->Name = L"show_rules_btn";
			this->show_rules_btn->Size = System::Drawing::Size(149, 67);
			this->show_rules_btn->TabIndex = 3;
			this->show_rules_btn->Text = L"Правила гри";
			this->show_rules_btn->UseVisualStyleBackColor = true;
			this->show_rules_btn->Click += gcnew System::EventHandler(this, &Welcome::show_rules_btn_Click);
			// 
			// hand_solver_btn
			// 
			this->hand_solver_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hand_solver_btn->Location = System::Drawing::Point(89, 200);
			this->hand_solver_btn->Name = L"hand_solver_btn";
			this->hand_solver_btn->Size = System::Drawing::Size(149, 67);
			this->hand_solver_btn->TabIndex = 4;
			this->hand_solver_btn->Text = L"Ручне розв\'язання";
			this->hand_solver_btn->UseVisualStyleBackColor = true;
			this->hand_solver_btn->Click += gcnew System::EventHandler(this, &Welcome::hand_solver_btn_Click);
			// 
			// Welcome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(352, 397);
			this->Controls->Add(this->hand_solver_btn);
			this->Controls->Add(this->show_rules_btn);
			this->Controls->Add(this->program_solver_btn);
			this->Controls->Add(this->size);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Welcome";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Skyscrapers";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->size))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Void program_solver_btn_Click(Object^, EventArgs^);
		Void show_rules_btn_Click(Object^, EventArgs^);
		Void hand_solver_btn_Click(Object^, EventArgs^);
};
}
