#pragma once

namespace Skyscrapers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Solver
	/// </summary>
	public ref class Solver : public System::Windows::Forms::Form
	{
	public:
		Solver(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		Solver(int);
		void clear_grid();
		bool check_input();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Solver()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int size;
	private: System::Windows::Forms::DataGridView^ grid;
	private: System::Windows::Forms::DataGridView^ top_clues;
	private: System::Windows::Forms::DataGridView^ bottom_clues;
	private: System::Windows::Forms::DataGridView^ left_clues;
	private: System::Windows::Forms::DataGridView^ right_clues;
	private: System::Windows::Forms::Label^ result_label;
	private: System::Windows::Forms::Button^ solve_btn;
	private: System::Windows::Forms::Button^ generation_btn;
	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->top_clues = (gcnew System::Windows::Forms::DataGridView());
			this->bottom_clues = (gcnew System::Windows::Forms::DataGridView());
			this->left_clues = (gcnew System::Windows::Forms::DataGridView());
			this->right_clues = (gcnew System::Windows::Forms::DataGridView());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->solve_btn = (gcnew System::Windows::Forms::Button());
			this->generation_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->top_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bottom_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->left_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->right_clues))->BeginInit();
			this->SuspendLayout();
			// 
			// grid
			// 
			this->grid->AllowUserToAddRows = false;
			this->grid->AllowUserToDeleteRows = false;
			this->grid->AllowUserToResizeColumns = false;
			this->grid->AllowUserToResizeRows = false;
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->grid->DefaultCellStyle = dataGridViewCellStyle1;
			this->grid->Location = System::Drawing::Point(74, 147);
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->RowHeadersWidth = 24;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			this->grid->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->grid->RowTemplate->Height = 24;
			this->grid->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->grid->Size = System::Drawing::Size(250, 250);
			this->grid->TabIndex = 0;
			this->grid->TabStop = false;
			// 
			// top_clues
			// 
			this->top_clues->AllowUserToAddRows = false;
			this->top_clues->AllowUserToDeleteRows = false;
			this->top_clues->AllowUserToResizeColumns = false;
			this->top_clues->AllowUserToResizeRows = false;
			this->top_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->top_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->top_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->top_clues->ColumnHeadersVisible = false;
			this->top_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->top_clues->DefaultCellStyle = dataGridViewCellStyle4;
			this->top_clues->Location = System::Drawing::Point(74, 90);
			this->top_clues->Name = L"top_clues";
			this->top_clues->RowHeadersVisible = false;
			this->top_clues->RowHeadersWidth = 24;
			this->top_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->top_clues->RowTemplate->Height = 24;
			this->top_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->top_clues->Size = System::Drawing::Size(250, 51);
			this->top_clues->TabIndex = 1;
			this->top_clues->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Solver::clues_CellValueChanged);
			// 
			// bottom_clues
			// 
			this->bottom_clues->AllowUserToAddRows = false;
			this->bottom_clues->AllowUserToDeleteRows = false;
			this->bottom_clues->AllowUserToResizeColumns = false;
			this->bottom_clues->AllowUserToResizeRows = false;
			this->bottom_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bottom_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->bottom_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->bottom_clues->ColumnHeadersVisible = false;
			this->bottom_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bottom_clues->DefaultCellStyle = dataGridViewCellStyle6;
			this->bottom_clues->Location = System::Drawing::Point(74, 403);
			this->bottom_clues->Name = L"bottom_clues";
			this->bottom_clues->RowHeadersVisible = false;
			this->bottom_clues->RowHeadersWidth = 24;
			this->bottom_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->bottom_clues->RowTemplate->Height = 24;
			this->bottom_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->bottom_clues->Size = System::Drawing::Size(250, 51);
			this->bottom_clues->TabIndex = 2;
			this->bottom_clues->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Solver::clues_CellValueChanged);
			// 
			// left_clues
			// 
			this->left_clues->AllowUserToAddRows = false;
			this->left_clues->AllowUserToDeleteRows = false;
			this->left_clues->AllowUserToResizeColumns = false;
			this->left_clues->AllowUserToResizeRows = false;
			this->left_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->left_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->left_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->left_clues->ColumnHeadersVisible = false;
			this->left_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->left_clues->DefaultCellStyle = dataGridViewCellStyle8;
			this->left_clues->Location = System::Drawing::Point(21, 147);
			this->left_clues->Name = L"left_clues";
			this->left_clues->RowHeadersVisible = false;
			this->left_clues->RowHeadersWidth = 24;
			this->left_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->left_clues->RowTemplate->Height = 24;
			this->left_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->left_clues->Size = System::Drawing::Size(47, 250);
			this->left_clues->TabIndex = 3;
			this->left_clues->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Solver::clues_CellValueChanged);
			// 
			// right_clues
			// 
			this->right_clues->AllowUserToAddRows = false;
			this->right_clues->AllowUserToDeleteRows = false;
			this->right_clues->AllowUserToResizeColumns = false;
			this->right_clues->AllowUserToResizeRows = false;
			this->right_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->right_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->right_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->right_clues->ColumnHeadersVisible = false;
			this->right_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle10->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->right_clues->DefaultCellStyle = dataGridViewCellStyle10;
			this->right_clues->Location = System::Drawing::Point(330, 147);
			this->right_clues->Name = L"right_clues";
			this->right_clues->RowHeadersVisible = false;
			this->right_clues->RowHeadersWidth = 24;
			this->right_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->right_clues->RowTemplate->Height = 24;
			this->right_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->right_clues->Size = System::Drawing::Size(47, 250);
			this->right_clues->TabIndex = 4;
			this->right_clues->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Solver::clues_CellValueChanged);
			// 
			// result_label
			// 
			this->result_label->AutoSize = true;
			this->result_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result_label->Location = System::Drawing::Point(71, 43);
			this->result_label->Name = L"result_label";
			this->result_label->Size = System::Drawing::Size(0, 29);
			this->result_label->TabIndex = 5;
			// 
			// solve_btn
			// 
			this->solve_btn->Location = System::Drawing::Point(428, 224);
			this->solve_btn->Name = L"solve_btn";
			this->solve_btn->Size = System::Drawing::Size(141, 71);
			this->solve_btn->TabIndex = 6;
			this->solve_btn->Text = L"Розв\'язати";
			this->solve_btn->UseVisualStyleBackColor = true;
			this->solve_btn->Click += gcnew System::EventHandler(this, &Solver::solve_btn_Click);
			// 
			// generation_btn
			// 
			this->generation_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->generation_btn->Location = System::Drawing::Point(428, 147);
			this->generation_btn->Name = L"generation_btn";
			this->generation_btn->Size = System::Drawing::Size(141, 71);
			this->generation_btn->TabIndex = 13;
			this->generation_btn->Text = L"Згенерувати головоломку";
			this->generation_btn->UseVisualStyleBackColor = true;
			this->generation_btn->Click += gcnew System::EventHandler(this, &Solver::generation_btn_Click);
			// 
			// Solver
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 567);
			this->Controls->Add(this->generation_btn);
			this->Controls->Add(this->solve_btn);
			this->Controls->Add(this->result_label);
			this->Controls->Add(this->right_clues);
			this->Controls->Add(this->left_clues);
			this->Controls->Add(this->bottom_clues);
			this->Controls->Add(this->top_clues);
			this->Controls->Add(this->grid);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Solver";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Skyscrapers";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->top_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bottom_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->left_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->right_clues))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	Void solve_btn_Click(Object^, EventArgs^);
	Void clues_CellValueChanged(Object^, DataGridViewCellEventArgs^);
	Void generation_btn_Click(Object^, EventArgs^);
};
}
