#include "grid.h"
#include <iostream>

Grid::Grid(int size) {
    this->size = size;

    cells = new Cell * [size];
    for (int i = 0; i < size; i++) {
        cells[i] = new Cell[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cells[i][j] = Cell(size);
        }
    }

    top_clues = new int[size];
    bottom_clues = new int[size];
    left_clues = new int[size];
    right_clues = new int[size];
}
void Grid::fill_grid(DataGridView^ grid) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!String::IsNullOrEmpty(Convert::ToString(grid->Rows[i]->Cells[j]->Value)))
                set_cell_to(i, j, Convert::ToInt32(grid->Rows[i]->Cells[j]->Value));
        }
    }
}

Grid::Grid(const Grid& obj) {
    this->size = obj.size;

    this->top_clues = new int[size];
    this->bottom_clues = new int[size];
    this->left_clues = new int[size];
    this->right_clues = new int[size];

    this->cells = new Cell * [size];
    for (int i = 0; i < this->size; i++) {
        this->cells[i] = new Cell[size];
    }

    for (int i = 0; i < this->size; i++) {
        this->top_clues[i] = obj.top_clues[i];
        this->bottom_clues[i] = obj.bottom_clues[i];
        this->left_clues[i] = obj.left_clues[i];
        this->right_clues[i] = obj.right_clues[i];

        for (int j = 0; j < size; j++) {
            this->cells[i][j] = obj.cells[i][j];
        }
    }
}
Grid& Grid::operator=(const Grid& obj) {
    delete[] top_clues;
    delete[] bottom_clues;
    delete[] left_clues;
    delete[] right_clues;

    for (int i = 0; i < size; i++)
        delete[] cells[i];
    delete[] cells;


    this->size = obj.size;

    this->top_clues = new int[size];
    this->bottom_clues = new int[size];
    this->left_clues = new int[size];
    this->right_clues = new int[size];

    this->cells = new Cell * [size];
    for (int i = 0; i < this->size; i++) {
        this->cells[i] = new Cell[size];
    }

    for (int i = 0; i < this->size; i++) {
        this->top_clues[i] = obj.top_clues[i];
        this->bottom_clues[i] = obj.bottom_clues[i];
        this->left_clues[i] = obj.left_clues[i];
        this->right_clues[i] = obj.right_clues[i];

        for (int j = 0; j < size; j++) {
            this->cells[i][j] = obj.cells[i][j];
        }
    }

    return *this;
}

Cell* Grid::operator[](int index) {
    return cells[index];
}

Cell** Grid::get_cells() {
    return cells;
}
int Grid::get_size() {
    return size;
}

void Grid::set_top_clues(DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        top_clues[i] = Convert::ToInt32(clues->Rows[0]->Cells[i]->Value);
    }
}
void Grid::set_bottom_clues(DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        bottom_clues[i] = Convert::ToInt32(clues->Rows[0]->Cells[i]->Value);
    }
}
void Grid::set_left_clues(DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        left_clues[i] = Convert::ToInt32(clues->Rows[i]->Cells[0]->Value);
    }
}
void Grid::set_right_clues(DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        right_clues[i] = Convert::ToInt32(clues->Rows[i]->Cells[0]->Value);
    }
}

void Grid::set_cell_to(int row, int col, int value) {
    for (int i = 0; i < size; i++) {
        cells[row][i].remove_possibility(value);
        cells[i][col].remove_possibility(value);
    }

    cells[row][col].set_value(value);
    cells[row][col].left_possibility(value);
}

bool Grid::is_filled() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (cells[i][j].get_value() == 0)
                return false;
        }
    }

    return true;
}
bool Grid::is_solved() {
    if (!is_filled())
        return false;

    int highest;
    int counter;
    //top
    for (int i = 0; i < size; i++) {
        highest = 0;
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (highest < cells[j][i].get_value()) {
                counter++;
                highest = cells[j][i].get_value();
            }
        }

        if (top_clues[i] != counter)
            return false;
    }


    //bottom
    for (int i = 0; i < size; i++) {
        highest = 0;
        counter = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (highest < cells[j][i].get_value()) {
                counter++;
                highest = cells[j][i].get_value();
            }
        }

        if (bottom_clues[i] != counter)
            return false;
    }


    //left
    for (int i = 0; i < size; i++) {
        highest = 0;
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (highest < cells[i][j].get_value()) {
                counter++;
                highest = cells[i][j].get_value();
            }
        }

        if (left_clues[i] != counter)
            return false;
    }


    //right
    for (int i = 0; i < size; i++) {
        highest = 0;
        counter = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (highest < cells[i][j].get_value()) {
                counter++;
                highest = cells[i][j].get_value();
            }
        }

        if (right_clues[i] != counter)
            return false;
    }

    return true;
}
bool Grid::is_solvable() {
    int counter, highest;
    for (int i = 0; i < size; i++) {
        //top
        highest = 0;
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (cells[j][i].get_possibilities().empty() && cells[j][i].get_value() == 0)
                return false;

            if (cells[j][i].get_value() == 0) {
                counter = top_clues[i];
                break;
            }

            if (highest < cells[j][i].get_value()) {
                counter++;
                highest = cells[j][i].get_value();
            }
        }

        if (top_clues[i] != counter)
            return false;

        //left
        highest = 0;
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (cells[i][j].get_value() == 0) {
                counter = left_clues[i];
                break;
            }

            if (highest < cells[i][j].get_value()) {
                counter++;
                highest = cells[i][j].get_value();
            }
        }

        if (left_clues[i] != counter)
            return false;


        //bottom
        highest = 0;
        counter = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (cells[j][i].get_value() == 0) {
                counter = bottom_clues[i];
                break;
            }
            if (highest < cells[j][i].get_value()) {
                counter++;
                highest = cells[j][i].get_value();
            }
        }

        if (bottom_clues[i] != counter)
            return false;


        //right
        highest = 0;
        counter = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (cells[i][j].get_value() == 0) {
                counter = right_clues[i];
                break;
            }

            if (highest < cells[i][j].get_value()) {
                counter++;
                highest = cells[i][j].get_value();
            }
        }

        if (right_clues[i] != counter)
            return false;
    }

    return true;
}

void Grid::remove_extra_possibilities() {
    //top
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < top_clues[i] - 1; j++) {
            for (int k = size; k > size - top_clues[i] + j + 1; k--) {
                cells[j][i].remove_possibility(k);
            }
        }
    }


    //bottom
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > size - bottom_clues[i]; j--) {
            for (int k = size; k > 2 * size - bottom_clues[i] - j; k--) {
                cells[j][i].remove_possibility(k);
            }
        }
    }

    //left
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < left_clues[i] - 1; j++) {
            for (int k = size; k > size - left_clues[i] + j + 1; k--) {
                cells[i][j].remove_possibility(k);
            }
        }
    }

    //right
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > size - right_clues[i]; j--) {
            for (int k = size; k > 2 * size - right_clues[i] - j; k--) {
                cells[i][j].remove_possibility(k);
            }
        }
    }
}
bool Grid::solve_basic_clues() {
    //top
    for (int i = 0; i < size; i++) {
        if (top_clues[i] == 1) {
            if (!cells[0][i].contain_possibility(size))
                return false;
            set_cell_to(0, i, size);
        }
        else if (top_clues[i] == size) {
            for (int j = 1; j <= size; j++) {
                if (!cells[j - 1][i].contain_possibility(j))
                    return false;
                set_cell_to(j - 1, i, j);
            }
        }
    }

    //bottom
    for (int i = 0; i < size; i++) {
        if (bottom_clues[i] == 1) {
            if (!cells[size - 1][i].contain_possibility(size))
                return false;
            set_cell_to(size - 1, i, size);
        }
        else if (bottom_clues[i] == size) {
            for (int j = size; j >= 1; j--) {
                if (!cells[j - 1][i].contain_possibility(size - j + 1))
                    return false;
                set_cell_to(j - 1, i, size - j + 1);
            }
        }
    }

    //left
    for (int i = 0; i < size; i++) {
        if (left_clues[i] == 1) {
            if (!cells[i][0].contain_possibility(size))
                return false;
            set_cell_to(i, 0, size);
        }
        else if (left_clues[i] == size) {
            for (int j = 1; j <= size; j++) {
                if (!cells[i][j - 1].contain_possibility(j))
                    return false;
                set_cell_to(i, j - 1, j);
            }
        }
    }

    //right
    for (int i = 0; i < size; i++) {
        if (right_clues[i] == 1) {
            if (!cells[i][size - 1].contain_possibility(size))
                return false;
            set_cell_to(i, size - 1, size);
        }
        else if (right_clues[i] == size) {
            for (int j = size; j >= 1; j--) {
                if (!cells[i][j - 1].contain_possibility(size - j + 1))
                    return false;
                set_cell_to(i, j - 1, size - j + 1);
            }
        }
    }

    return true;
}
void Grid::remove_single_possibility() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((cells[i][j].get_possibilities().size() == 1) && (cells[i][j].get_value() == 0)) {
                int value = cells[i][j].get_possibilities()[0];
                set_cell_to(i, j, value);
            }
        }
    }
}
bool solve(Grid& puzzle) {
    if (puzzle.is_solved())
        return true;

    if (!puzzle.is_solvable())
        return false;

    int row, col;
    int length = puzzle.get_size() + 1;
    for (int i = 0; i < puzzle.get_size(); i++) {
        for (int j = 0; j < puzzle.get_size(); j++) {
            if (puzzle[i][j].get_value() == 0 && puzzle[i][j].get_possibilities().size() < length) {
                row = i;
                col = j;
                length = puzzle[i][j].get_possibilities().size();
            }
        }
    }

    vector<int> possibilities = puzzle[row][col].get_possibilities();
    for (int i = 0; i < possibilities.size(); i++) {
        Grid temp(puzzle);
 
        temp.set_cell_to(row, col, possibilities[i]);
        temp.remove_single_possibility();

        if (!temp.is_solvable()) {
            continue;
        }
        else if (temp.is_solved()) {
            puzzle = temp;
            return true;
        }
        else if (!temp.is_filled()) {
            if (solve(temp)) {
                puzzle = temp;
                return true;
            }
        }
    }

    return false;
}

void Grid::display(DataGridView^ dest) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dest->Rows[i]->Cells[j]->Value = Convert::ToString(cells[i][j].get_value());
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i < size; i++) {
        delete[] cells[i];
    }

    delete[] cells;

    delete[] top_clues;
    delete[] bottom_clues;
    delete[] left_clues;
    delete[] right_clues;
}