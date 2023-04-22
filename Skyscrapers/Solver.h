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
		Void clear_grid();
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->top_clues = (gcnew System::Windows::Forms::DataGridView());
			this->bottom_clues = (gcnew System::Windows::Forms::DataGridView());
			this->left_clues = (gcnew System::Windows::Forms::DataGridView());
			this->right_clues = (gcnew System::Windows::Forms::DataGridView());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->solve_btn = (gcnew System::Windows::Forms::Button());
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
			dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle21->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle21->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle21->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle21->SelectionForeColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->grid->DefaultCellStyle = dataGridViewCellStyle21;
			this->grid->Location = System::Drawing::Point(74, 147);
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->RowHeadersWidth = 24;
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle22->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			this->grid->RowsDefaultCellStyle = dataGridViewCellStyle22;
			this->grid->RowTemplate->Height = 24;
			this->grid->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->grid->Size = System::Drawing::Size(250, 250);
			this->grid->TabIndex = 0;
			// 
			// top_clues
			// 
			this->top_clues->AllowUserToAddRows = false;
			this->top_clues->AllowUserToDeleteRows = false;
			this->top_clues->AllowUserToResizeColumns = false;
			this->top_clues->AllowUserToResizeRows = false;
			this->top_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle23->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle23->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle23->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle23->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle23->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->top_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle23;
			this->top_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->top_clues->ColumnHeadersVisible = false;
			this->top_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle24->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle24->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle24->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle24->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle24->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->top_clues->DefaultCellStyle = dataGridViewCellStyle24;
			this->top_clues->Location = System::Drawing::Point(74, 90);
			this->top_clues->Name = L"top_clues";
			this->top_clues->RowHeadersVisible = false;
			this->top_clues->RowHeadersWidth = 24;
			this->top_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->top_clues->RowTemplate->Height = 24;
			this->top_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->top_clues->Size = System::Drawing::Size(250, 51);
			this->top_clues->TabIndex = 1;
			// 
			// bottom_clues
			// 
			this->bottom_clues->AllowUserToAddRows = false;
			this->bottom_clues->AllowUserToDeleteRows = false;
			this->bottom_clues->AllowUserToResizeColumns = false;
			this->bottom_clues->AllowUserToResizeRows = false;
			this->bottom_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle25->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle25->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle25->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle25->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle25->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bottom_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle25;
			this->bottom_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->bottom_clues->ColumnHeadersVisible = false;
			this->bottom_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle26->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle26->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle26->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle26->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle26->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bottom_clues->DefaultCellStyle = dataGridViewCellStyle26;
			this->bottom_clues->Location = System::Drawing::Point(74, 403);
			this->bottom_clues->Name = L"bottom_clues";
			this->bottom_clues->RowHeadersVisible = false;
			this->bottom_clues->RowHeadersWidth = 24;
			this->bottom_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->bottom_clues->RowTemplate->Height = 24;
			this->bottom_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->bottom_clues->Size = System::Drawing::Size(250, 51);
			this->bottom_clues->TabIndex = 2;
			// 
			// left_clues
			// 
			this->left_clues->AllowUserToAddRows = false;
			this->left_clues->AllowUserToDeleteRows = false;
			this->left_clues->AllowUserToResizeColumns = false;
			this->left_clues->AllowUserToResizeRows = false;
			this->left_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle27->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle27->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle27->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->left_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle27;
			this->left_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->left_clues->ColumnHeadersVisible = false;
			this->left_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle28->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle28->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle28->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle28->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle28->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->left_clues->DefaultCellStyle = dataGridViewCellStyle28;
			this->left_clues->Location = System::Drawing::Point(21, 147);
			this->left_clues->Name = L"left_clues";
			this->left_clues->RowHeadersVisible = false;
			this->left_clues->RowHeadersWidth = 24;
			this->left_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->left_clues->RowTemplate->Height = 24;
			this->left_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->left_clues->Size = System::Drawing::Size(47, 250);
			this->left_clues->TabIndex = 3;
			// 
			// right_clues
			// 
			this->right_clues->AllowUserToAddRows = false;
			this->right_clues->AllowUserToDeleteRows = false;
			this->right_clues->AllowUserToResizeColumns = false;
			this->right_clues->AllowUserToResizeRows = false;
			this->right_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle29->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle29->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle29->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle29->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle29->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->right_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle29;
			this->right_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->right_clues->ColumnHeadersVisible = false;
			this->right_clues->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle30->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle30->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle30->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->right_clues->DefaultCellStyle = dataGridViewCellStyle30;
			this->right_clues->Location = System::Drawing::Point(330, 147);
			this->right_clues->Name = L"right_clues";
			this->right_clues->RowHeadersVisible = false;
			this->right_clues->RowHeadersWidth = 24;
			this->right_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->right_clues->RowTemplate->Height = 24;
			this->right_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->right_clues->Size = System::Drawing::Size(47, 250);
			this->right_clues->TabIndex = 4;
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
			this->solve_btn->Location = System::Drawing::Point(433, 147);
			this->solve_btn->Name = L"solve_btn";
			this->solve_btn->Size = System::Drawing::Size(141, 54);
			this->solve_btn->TabIndex = 6;
			this->solve_btn->Text = L"Розв\'язати";
			this->solve_btn->UseVisualStyleBackColor = true;
			this->solve_btn->Click += gcnew System::EventHandler(this, &Solver::solve_btn_Click);
			// 
			// Solver
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 567);
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
private: Void solve_btn_Click(Object^, EventArgs^);
};
}
