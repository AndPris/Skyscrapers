#pragma once

namespace Skyscrapers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Puzzle
	/// </summary>
	public ref class Puzzle : public System::Windows::Forms::Form
	{
	public:
		Puzzle(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		Puzzle(int);
		void clear_grid();
		bool is_filled();
		bool check_input();
		bool has_repeat();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Puzzle()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ result_label;
	private: System::Windows::Forms::DataGridView^ right_clues;
	private: System::Windows::Forms::DataGridView^ left_clues;
	private: System::Windows::Forms::DataGridView^ bottom_clues;
	private: System::Windows::Forms::DataGridView^ top_clues;
	private: System::Windows::Forms::DataGridView^ grid;
	private: System::Windows::Forms::Button^ generation_btn;
	private: System::Windows::Forms::Button^ check_btn;
	private: System::Windows::Forms::Button^ hint_btn;

		int size;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->right_clues = (gcnew System::Windows::Forms::DataGridView());
			this->left_clues = (gcnew System::Windows::Forms::DataGridView());
			this->bottom_clues = (gcnew System::Windows::Forms::DataGridView());
			this->top_clues = (gcnew System::Windows::Forms::DataGridView());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->generation_btn = (gcnew System::Windows::Forms::Button());
			this->check_btn = (gcnew System::Windows::Forms::Button());
			this->hint_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->right_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->left_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bottom_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->top_clues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->SuspendLayout();
			// 
			// result_label
			// 
			this->result_label->AutoSize = true;
			this->result_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result_label->Location = System::Drawing::Point(16, 23);
			this->result_label->Name = L"result_label";
			this->result_label->Size = System::Drawing::Size(0, 29);
			this->result_label->TabIndex = 11;
			// 
			// right_clues
			// 
			this->right_clues->AllowUserToAddRows = false;
			this->right_clues->AllowUserToDeleteRows = false;
			this->right_clues->AllowUserToResizeColumns = false;
			this->right_clues->AllowUserToResizeRows = false;
			this->right_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->right_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle11;
			this->right_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->right_clues->ColumnHeadersVisible = false;
			this->right_clues->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle12->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->right_clues->DefaultCellStyle = dataGridViewCellStyle12;
			this->right_clues->Location = System::Drawing::Point(330, 147);
			this->right_clues->Name = L"right_clues";
			this->right_clues->ReadOnly = true;
			this->right_clues->RowHeadersVisible = false;
			this->right_clues->RowHeadersWidth = 24;
			this->right_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->right_clues->RowTemplate->Height = 24;
			this->right_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->right_clues->Size = System::Drawing::Size(47, 250);
			this->right_clues->TabIndex = 10;
			// 
			// left_clues
			// 
			this->left_clues->AllowUserToAddRows = false;
			this->left_clues->AllowUserToDeleteRows = false;
			this->left_clues->AllowUserToResizeColumns = false;
			this->left_clues->AllowUserToResizeRows = false;
			this->left_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle13->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle13->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle13->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle13->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->left_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle13;
			this->left_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->left_clues->ColumnHeadersVisible = false;
			this->left_clues->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle14->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle14->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle14->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle14->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->left_clues->DefaultCellStyle = dataGridViewCellStyle14;
			this->left_clues->Location = System::Drawing::Point(21, 147);
			this->left_clues->Name = L"left_clues";
			this->left_clues->ReadOnly = true;
			this->left_clues->RowHeadersVisible = false;
			this->left_clues->RowHeadersWidth = 24;
			this->left_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->left_clues->RowTemplate->Height = 24;
			this->left_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->left_clues->Size = System::Drawing::Size(47, 250);
			this->left_clues->TabIndex = 9;
			// 
			// bottom_clues
			// 
			this->bottom_clues->AllowUserToAddRows = false;
			this->bottom_clues->AllowUserToDeleteRows = false;
			this->bottom_clues->AllowUserToResizeColumns = false;
			this->bottom_clues->AllowUserToResizeRows = false;
			this->bottom_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle15->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle15->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle15->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bottom_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle15;
			this->bottom_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->bottom_clues->ColumnHeadersVisible = false;
			this->bottom_clues->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle16->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle16->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bottom_clues->DefaultCellStyle = dataGridViewCellStyle16;
			this->bottom_clues->Location = System::Drawing::Point(74, 403);
			this->bottom_clues->Name = L"bottom_clues";
			this->bottom_clues->ReadOnly = true;
			this->bottom_clues->RowHeadersVisible = false;
			this->bottom_clues->RowHeadersWidth = 24;
			this->bottom_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->bottom_clues->RowTemplate->Height = 24;
			this->bottom_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->bottom_clues->Size = System::Drawing::Size(250, 51);
			this->bottom_clues->TabIndex = 8;
			// 
			// top_clues
			// 
			this->top_clues->AllowUserToAddRows = false;
			this->top_clues->AllowUserToDeleteRows = false;
			this->top_clues->AllowUserToResizeColumns = false;
			this->top_clues->AllowUserToResizeRows = false;
			this->top_clues->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle17->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle17->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle17->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle17->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->top_clues->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
			this->top_clues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->top_clues->ColumnHeadersVisible = false;
			this->top_clues->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle18->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle18->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->top_clues->DefaultCellStyle = dataGridViewCellStyle18;
			this->top_clues->Location = System::Drawing::Point(74, 90);
			this->top_clues->Name = L"top_clues";
			this->top_clues->ReadOnly = true;
			this->top_clues->RowHeadersVisible = false;
			this->top_clues->RowHeadersWidth = 24;
			this->top_clues->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->top_clues->RowTemplate->Height = 24;
			this->top_clues->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->top_clues->Size = System::Drawing::Size(250, 51);
			this->top_clues->TabIndex = 7;
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
			this->grid->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle19->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle19->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle19->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle19->SelectionForeColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle19->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->grid->DefaultCellStyle = dataGridViewCellStyle19;
			this->grid->Location = System::Drawing::Point(74, 147);
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->RowHeadersWidth = 24;
			dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle20->BackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			this->grid->RowsDefaultCellStyle = dataGridViewCellStyle20;
			this->grid->RowTemplate->Height = 24;
			this->grid->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->grid->Size = System::Drawing::Size(250, 250);
			this->grid->TabIndex = 6;
			// 
			// generation_btn
			// 
			this->generation_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->generation_btn->Location = System::Drawing::Point(450, 147);
			this->generation_btn->Name = L"generation_btn";
			this->generation_btn->Size = System::Drawing::Size(141, 71);
			this->generation_btn->TabIndex = 12;
			this->generation_btn->Text = L"Згенерувати головоломку";
			this->generation_btn->UseVisualStyleBackColor = true;
			this->generation_btn->Click += gcnew System::EventHandler(this, &Puzzle::generation_btn_Click);
			// 
			// check_btn
			// 
			this->check_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->check_btn->Enabled = false;
			this->check_btn->Location = System::Drawing::Point(450, 224);
			this->check_btn->Name = L"check_btn";
			this->check_btn->Size = System::Drawing::Size(141, 71);
			this->check_btn->TabIndex = 13;
			this->check_btn->Text = L"Перевірити";
			this->check_btn->UseVisualStyleBackColor = true;
			this->check_btn->Click += gcnew System::EventHandler(this, &Puzzle::check_btn_Click);
			// 
			// hint_btn
			// 
			this->hint_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hint_btn->Enabled = false;
			this->hint_btn->Location = System::Drawing::Point(450, 301);
			this->hint_btn->Name = L"hint_btn";
			this->hint_btn->Size = System::Drawing::Size(141, 71);
			this->hint_btn->TabIndex = 14;
			this->hint_btn->Text = L"Підказка";
			this->hint_btn->UseVisualStyleBackColor = true;
			this->hint_btn->Click += gcnew System::EventHandler(this, &Puzzle::hint_btn_Click);
			// 
			// Puzzle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(868, 567);
			this->Controls->Add(this->hint_btn);
			this->Controls->Add(this->check_btn);
			this->Controls->Add(this->generation_btn);
			this->Controls->Add(this->result_label);
			this->Controls->Add(this->right_clues);
			this->Controls->Add(this->left_clues);
			this->Controls->Add(this->bottom_clues);
			this->Controls->Add(this->top_clues);
			this->Controls->Add(this->grid);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Puzzle";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Skyscrapers";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->right_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->left_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bottom_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->top_clues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Void generation_btn_Click(Object^, EventArgs^);
		Void check_btn_Click(Object^, EventArgs^);
		Void hint_btn_Click(Object^, EventArgs^);
};
}
