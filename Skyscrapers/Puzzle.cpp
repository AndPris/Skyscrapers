#define CELL_SIZE 40

#include "Puzzle.h"
#include "Generator.h"
#include "Grid.h"
#include <stdlib.h>
#include <ctime>

using namespace Skyscrapers;

int amount_of_hints = 0;


Puzzle::Puzzle(int size) {

	InitializeComponent();
	this->size = size;

	//grid configuration
	grid->Size = Drawing::Size(size * CELL_SIZE, size * CELL_SIZE);
	grid->ColumnCount = size;
	grid->RowCount = size;
	for (int i = 0; i < size-1; i++) {
		grid->Rows[i]->Height = CELL_SIZE;
	}
	grid->Rows[size-1]->Height = CELL_SIZE - 3;

	//top clues configuration
	top_clues->ColumnCount = size;
	top_clues->RowCount = 1;
	top_clues->Location = Point(grid->Location.X, grid->Location.Y - CELL_SIZE);
	top_clues->Size = Drawing::Size(grid->Size.Width, CELL_SIZE);
	top_clues->Rows[0]->Height = CELL_SIZE;

	//bottom clues configuration
	bottom_clues->ColumnCount = size;
	bottom_clues->RowCount = 1;
	bottom_clues->Location = Point(grid->Location.X, grid->Location.Y + grid->Size.Height);
	bottom_clues->Size = Drawing::Size(grid->Size.Width, CELL_SIZE);
	bottom_clues->Rows[0]->Height = CELL_SIZE;

	//left clues configuration
	left_clues->ColumnCount = 1;
	left_clues->RowCount = size;
	left_clues->Location = Point(grid->Location.X - CELL_SIZE, grid->Location.Y);
	left_clues->Size = Drawing::Size(CELL_SIZE, grid->Size.Height);
	for (int i = 0; i < size - 1; i++) {
		left_clues->Rows[i]->Height = CELL_SIZE;
	}
	left_clues->Rows[size - 1]->Height = CELL_SIZE - 3;

	//righr clues configuration
	right_clues->ColumnCount = 1;
	right_clues->RowCount = size;
	right_clues->Location = Point(grid->Location.X + grid->Size.Width, grid->Location.Y);
	right_clues->Size = Drawing::Size(CELL_SIZE, grid->Size.Height);
	for (int i = 0; i < size - 1; i++) {
		right_clues->Rows[i]->Height = CELL_SIZE;
	}
	right_clues->Rows[size - 1]->Height = CELL_SIZE - 3;

	//generation button configuration
	generation_btn->Location = Point(right_clues->Location.X + CELL_SIZE * 2, grid->Location.Y);

	//check button configuration
	check_btn->Location = Point(generation_btn->Location.X, generation_btn->Location.Y + generation_btn->Size.Height + 5);
	
	//hint button configuration
	hint_btn->Location = Point(check_btn->Location.X, check_btn->Location.Y + check_btn->Size.Height + 5);

	save_btn->Location = Point(hint_btn->Location.X, hint_btn->Location.Y + hint_btn->Size.Height + 5);
}


Puzzle::Puzzle(StreamReader^ f) {

	InitializeComponent();
	this->size = f->Read() - '0';
	int value;

	//grid configuration
	grid->Size = Drawing::Size(size * CELL_SIZE, size * CELL_SIZE);
	grid->ColumnCount = size;
	grid->RowCount = size;
	for (int i = 0; i < size - 1; i++) {
		grid->Rows[i]->Height = CELL_SIZE;
	}
	grid->Rows[size - 1]->Height = CELL_SIZE - 3;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			value = f->Read() - '0';
			if (value)
				grid->Rows[i]->Cells[j]->Value = Convert::ToString(value);
		}
	}
	//top clues configuration
	top_clues->ColumnCount = size;
	top_clues->RowCount = 1;
	top_clues->Location = Point(grid->Location.X, grid->Location.Y - CELL_SIZE);
	top_clues->Size = Drawing::Size(grid->Size.Width, CELL_SIZE);
	top_clues->Rows[0]->Height = CELL_SIZE;

	for (int i = 0; i < size; i++) {
		value = f->Read() - '0';
		if (value)
			top_clues->Rows[0]->Cells[i]->Value = Convert::ToString(value);
	}
	//bottom clues configuration
	bottom_clues->ColumnCount = size;
	bottom_clues->RowCount = 1;
	bottom_clues->Location = Point(grid->Location.X, grid->Location.Y + grid->Size.Height);
	bottom_clues->Size = Drawing::Size(grid->Size.Width, CELL_SIZE);
	bottom_clues->Rows[0]->Height = CELL_SIZE;

	for (int i = 0; i < size; i++) {
		value = f->Read() - '0';
		if (value)
			bottom_clues->Rows[0]->Cells[i]->Value = Convert::ToString(value);
	}
	//left clues configuration
	left_clues->ColumnCount = 1;
	left_clues->RowCount = size;
	left_clues->Location = Point(grid->Location.X - CELL_SIZE, grid->Location.Y);
	left_clues->Size = Drawing::Size(CELL_SIZE, grid->Size.Height);
	for (int i = 0; i < size - 1; i++) {
		left_clues->Rows[i]->Height = CELL_SIZE;
	}
	left_clues->Rows[size - 1]->Height = CELL_SIZE - 3;

	for (int i = 0; i < size; i++) {
		value = f->Read() - '0';
		if (value)
			left_clues->Rows[i]->Cells[0]->Value = Convert::ToString(value);
	}
	//right clues configuration
	right_clues->ColumnCount = 1;
	right_clues->RowCount = size;
	right_clues->Location = Point(grid->Location.X + grid->Size.Width, grid->Location.Y);
	right_clues->Size = Drawing::Size(CELL_SIZE, grid->Size.Height);
	for (int i = 0; i < size - 1; i++) {
		right_clues->Rows[i]->Height = CELL_SIZE;
	}
	right_clues->Rows[size - 1]->Height = CELL_SIZE - 3;

	for (int i = 0; i < size; i++) {
		value = f->Read() - '0';
		if (value)
			right_clues->Rows[i]->Cells[0]->Value = Convert::ToString(value);
	}
	f->Read();

	//generation button configuration
	generation_btn->Location = Point(right_clues->Location.X + CELL_SIZE * 2, grid->Location.Y);

	//check button configuration
	check_btn->Location = Point(generation_btn->Location.X, generation_btn->Location.Y + generation_btn->Size.Height + 5);
	String^ state = f->ReadLine();
	if (state == "True")
		check_btn->Enabled = true;

	//hint button configuration
	hint_btn->Location = Point(check_btn->Location.X, check_btn->Location.Y + check_btn->Size.Height + 5);
	state = f->ReadLine();
	if (state == "True")
		hint_btn->Enabled = true;

	state = f->ReadLine();
	if (state == "False")
		grid->ReadOnly = false;

	save_btn->Location = Point(hint_btn->Location.X, hint_btn->Location.Y + hint_btn->Size.Height + 5);
}


void Puzzle::clear_grid() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			grid->Rows[i]->Cells[j]->Value = "";
		}
	}

}
Void Puzzle::generation_btn_Click(Object^ sender, EventArgs^ e) {
	clear_grid();
	result_label->Text = "";
	grid->ReadOnly = false;
	check_btn->Enabled = true;
	hint_btn->Enabled = true;
	amount_of_hints = 0;

	int** puzzle = create_matrix(size);
	create_puzzle(puzzle, size, 0);

	create_top_clues(puzzle, size, top_clues);
	create_bottom_clues(puzzle, size, bottom_clues);
	create_left_clues(puzzle, size, left_clues);
	create_right_clues(puzzle, size, right_clues);

	delete_matrix(puzzle, size);
}

bool Puzzle::is_filled() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//if one of cells is empty
			if (String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[j]->Value))) {
				result_label->ForeColor = Color::Red;
				result_label->Text = "Ви маєте заповнити всі клітинки!";
				return false;
			}
		}
	}

	return true;
}
bool Puzzle::check_input() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//if one of cells contains symbol or value out of range
			int value;
			if ((!int::TryParse(Convert::ToString(grid->Rows[i]->Cells[j]->Value), value)
				|| value < 1 || value > size) && (!String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[j]->Value)))) {
				result_label->ForeColor = Color::Red;
				result_label->Text = "Ви маєте вводити лише цілі числа від 1 до " + Convert::ToString(size);
				return false;
			}
		}
	}

	return true;
}
bool Puzzle::has_repeat() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[j]->Value)))
				continue;

			int value = Convert::ToInt32(grid->Rows[i]->Cells[j]->Value);

			for (int k = j + 1; k < size; k++) {
				if (String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[k]->Value)))
					continue;
				if (value == Convert::ToInt32(grid->Rows[i]->Cells[k]->Value))
					return true;
			}
			for (int k = i + 1; k < size; k++) {
				if (String::IsNullOrEmpty(Convert::ToString(grid->Rows[k]->Cells[j]->Value)))
					continue;
				if (value == Convert::ToInt32(grid->Rows[k]->Cells[j]->Value))
					return true;
			}
		}
	}

	return false;
}
Void Puzzle::check_btn_Click(Object^ sender, EventArgs^ e) {
	if (!is_filled())
		return;
	if (!check_input())
		return;

	if (has_repeat()) {
		result_label->ForeColor = Color::Red;
		result_label->Text = "У кожному рядочку і стовпчику всі числа мають бути різними!";
		return;
	}

	Grid puzzle(size);
	puzzle.fill_grid(grid);
	puzzle.set_top_clues(top_clues);
	puzzle.set_bottom_clues(bottom_clues);
	puzzle.set_left_clues(left_clues);
	puzzle.set_right_clues(right_clues);

	if (puzzle.is_solved()) {
		result_label->ForeColor = Color::Green;
		result_label->Text = "Правильно!";
	}
	else {
		result_label->ForeColor = Color::Red;
		result_label->Text = "Неправильно!";
	}
}

Void Puzzle::hint_btn_Click(Object^ sender, EventArgs^ e) {
	if (!check_input())
		return;

	if (has_repeat()) {
		result_label->ForeColor = Color::Red;
		result_label->Text = "У кожному рядочку і стовпчику всі числа мають бути різними!";
		return;
	}

	amount_of_hints++;

	if (amount_of_hints >= 3)
		hint_btn->Enabled = false;


	Grid puzzle(size);
	puzzle.fill_grid(grid);
	puzzle.set_top_clues(top_clues);
	puzzle.set_bottom_clues(bottom_clues);
	puzzle.set_left_clues(left_clues);
	puzzle.set_right_clues(right_clues);

	if (puzzle.is_solved()) {
		result_label->ForeColor = Color::Green;
		result_label->Text = "Головоломку вже розв'язано!";
	}else {
		srand(time(nullptr));

		puzzle.remove_extra_possibilities();
		if (!puzzle.solve_basic_clues()) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "За таких введених значень головоломку розв'язати не можна!";
			return;
		}
		puzzle.remove_single_possibility();

		if (!puzzle.solve()) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "За таких введених значень головоломку розв'язати не можна!";
			return;
		}

		int row, col;
		do {
			row = rand() % size;
			col = rand() % size;
		} while (!String::IsNullOrEmpty(Convert::ToString(grid->Rows[row]->Cells[col]->Value)));

		grid->Rows[row]->Cells[col]->Value = Convert::ToString(puzzle[row][col].get_value());
	}
}

Void Puzzle::grid_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e) {
	result_label->Text = "";
}

Void Puzzle::save_btn_Click(Object^ sender, EventArgs^ e) {
	SaveFileDialog^ file = gcnew SaveFileDialog();
	file->Filter = "Text file | *.txt";
	file->Title = "Save game!";
	file->InitialDirectory = Application::StartupPath;

	if (file->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		StreamWriter^ f = gcnew StreamWriter(file->FileName);
		f->Write(Convert::ToString(size));

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[j]->Value)))
					f->Write("0");
				else
					f->Write(Convert::ToString(grid->Rows[i]->Cells[j]->Value));
			}
		}

		for (int i = 0; i < size; i++) {
			if (String::IsNullOrEmpty(Convert::ToString(top_clues->Rows[0]->Cells[i]->Value)))
				f->Write("0");
			else
				f->Write(Convert::ToString(top_clues->Rows[0]->Cells[i]->Value));
		}

		for (int i = 0; i < size; i++) {
			if (String::IsNullOrEmpty(Convert::ToString(bottom_clues->Rows[0]->Cells[i]->Value)))
				f->Write("0");
			else
				f->Write(Convert::ToString(bottom_clues->Rows[0]->Cells[i]->Value));
		}

		for (int i = 0; i < size; i++) {
			if (String::IsNullOrEmpty(Convert::ToString(left_clues->Rows[i]->Cells[0]->Value)))
				f->Write("0");
			else
				f->Write(Convert::ToString(left_clues->Rows[i]->Cells[0]->Value));
		}

		for (int i = 0; i < size; i++) {
			if (String::IsNullOrEmpty(Convert::ToString(right_clues->Rows[i]->Cells[0]->Value)))
				f->Write("0");
			else
				f->Write(Convert::ToString(right_clues->Rows[i]->Cells[0]->Value));
		}

		f->Write('\n');
		f->Write(Convert::ToString(check_btn->Enabled));
		f->Write('\n');
		f->Write(Convert::ToString(hint_btn->Enabled));
		f->Write('\n');
		f->Write(Convert::ToString(grid->ReadOnly));

		f->Close();
	}
}
