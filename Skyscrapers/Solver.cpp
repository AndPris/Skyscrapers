#define CELL_SIZE 40

#include "Solver.h"
#include "Grid.h"

using namespace Skyscrapers;

Solver::Solver(int size) {
	InitializeComponent();
	this->size = size;

	//grid configuration
	grid->Size = Drawing::Size(size * CELL_SIZE, size * CELL_SIZE);
	grid->ColumnCount = size;
	grid->RowCount = size;
	for (int i = 0; i < size; i++) {
		grid->Rows[i]->Height = CELL_SIZE;
	}


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
	for (int i = 0; i < size-1; i++) {
		left_clues->Rows[i]->Height = CELL_SIZE;
	}
	left_clues->Rows[size-1]->Height = CELL_SIZE-3;

	//righr clues configuration
	right_clues->ColumnCount = 1;
	right_clues->RowCount = size;
	right_clues->Location = Point(grid->Location.X + grid->Size.Width, grid->Location.Y);
	right_clues->Size = Drawing::Size(CELL_SIZE, grid->Size.Height);
	for (int i = 0; i < size - 1; i++) {
		right_clues->Rows[i]->Height = CELL_SIZE;
	}
	right_clues->Rows[size - 1]->Height = CELL_SIZE - 3;

	//solve button configuration
	solve_btn->Location = Point(right_clues->Location.X + CELL_SIZE * 2, grid->Location.Y);
}

void Solver::clear_grid() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			grid->Rows[i]->Cells[j]->Value = "";
		}
	}

}

bool Solver::check_input() {
	for (int i = 0; i < size; i++) {
		//if one of cells is empty
		if (String::IsNullOrEmpty(Convert::ToString(top_clues->Rows[0]->Cells[i]->Value))) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте заповнити всі клітинки!";
			return false;
		}

		if (String::IsNullOrEmpty(Convert::ToString(bottom_clues->Rows[0]->Cells[i]->Value))) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте заповнити всі клітинки!";
			return false;
		}

		if (String::IsNullOrEmpty(Convert::ToString(left_clues->Rows[i]->Cells[0]->Value))) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте заповнити всі клітинки!";
			return false;
		}

		if (String::IsNullOrEmpty(Convert::ToString(right_clues->Rows[i]->Cells[0]->Value))) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте заповнити всі клітинки!";
			return false;
		}

		//if one of cells contains symbol or value out of range
		int value;
		if (!int::TryParse(Convert::ToString(top_clues->Rows[0]->Cells[i]->Value), value)
			|| value < 1 || value > size) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте вводити лише цілі числа від 1 до " + Convert::ToString(size);
			return false;
		}

		if (!int::TryParse(Convert::ToString(bottom_clues->Rows[0]->Cells[i]->Value), value)
			|| value < 1 || value > size) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте вводити лише цілі числа від 1 до " + Convert::ToString(size);
			return false;
		}

		if (!int::TryParse(Convert::ToString(left_clues->Rows[i]->Cells[0]->Value), value)
			|| value < 1 || value > size) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте вводити лише цілі числа від 1 до " + Convert::ToString(size);
			return false;
		}

		if (!int::TryParse(Convert::ToString(right_clues->Rows[i]->Cells[0]->Value), value)
			|| value < 1 || value > size) {
			result_label->ForeColor = Color::Red;
			result_label->Text = "Ви маєте вводити лише цілі числа від 1 до " + Convert::ToString(size);
			return false;
		}
	}
	
	return true;
}

Void Solver::solve_btn_Click(Object^ sender, EventArgs^ e) {
	clear_grid();
	solve_btn->Enabled = false;

	if (!check_input())
		return;

	Grid puzzle(size);

	puzzle.set_top_clues(top_clues);
	puzzle.set_bottom_clues(bottom_clues);
	puzzle.set_left_clues(left_clues);
	puzzle.set_right_clues(right_clues);

	puzzle.remove_extra_possibilities();

	if (!puzzle.solve_basic_clues()) {
		result_label->ForeColor = Color::Red;
		result_label->Text = "Ця головоломка не має розв'язку!";
		return;
	}

	puzzle.remove_single_possibility();
	if (!solve(puzzle)) {
		result_label->ForeColor = Color::Red;
		result_label->Text = "Ця головоломка не має розв'язку!";
		return;
	}

	puzzle.display(grid);
	result_label->ForeColor = Color::Green;
	result_label->Text = "Розв'язано!";
}

Void Solver::clues_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e) {
	solve_btn->Enabled = true;
}
