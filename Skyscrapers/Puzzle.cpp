#define CELL_SIZE 40

#include "Puzzle.h"
#include "Generator.h"
#include "Grid.h"
#include <stdlib.h>
#include <ctime>

using namespace Skyscrapers;

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
	for (int i = 0; i < size; i++) {
		right_clues->Rows[i]->Height = CELL_SIZE;
	}

	//generation button configuration
	generation_btn->Location = Point(right_clues->Location.X + CELL_SIZE * 2, grid->Location.Y);

	//check button configuration
	check_btn->Location = Point(generation_btn->Location.X, generation_btn->Location.Y + generation_btn->Size.Height + 5);
	
	//hint button configuration
	hint_btn->Location = Point(check_btn->Location.X, check_btn->Location.Y + check_btn->Size.Height + 5);
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
	grid->ReadOnly = false;
	check_btn->Enabled = true;
	hint_btn->Enabled = true;

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
		result_label->Text = "Правильно!";
	}
	else {
		result_label->Text = "Неправильно!";
	}
}

Void Puzzle::hint_btn_Click(Object^ sender, EventArgs^ e) {
	if (!check_input())
		return;

	if (has_repeat()) {
		result_label->Text = "У кожному рядочку і стовпчику всі числа мають бути різними!";
		return;
	}

	hint_btn->Enabled = false;

	Grid puzzle(size);
	puzzle.fill_grid(grid);
	puzzle.set_top_clues(top_clues);
	puzzle.set_bottom_clues(bottom_clues);
	puzzle.set_left_clues(left_clues);
	puzzle.set_right_clues(right_clues);

	if (puzzle.is_solved()) {
		result_label->Text = "Головоломку вже розв'язано!";
	} else if(!puzzle.is_solvable()) {
		result_label->Text = "За таких введених значень головоломку розв'язати не можна!";
	} else {
		srand(time(NULL));

		puzzle.remove_extra_possibilities();
		puzzle.solve_basic_clues();
		puzzle.remove_single_possibility();
		solve(puzzle);

		int row, col;
		do {
			row = rand() % size;
			col = rand() % size;
		} while (!String::IsNullOrEmpty(Convert::ToString(grid->Rows[row]->Cells[col]->Value)));

		grid->Rows[row]->Cells[col]->Value = Convert::ToString(puzzle[row][col].get_value());
	}
}