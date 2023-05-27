#pragma once

#include "cell.h"
using namespace System;
using namespace Windows::Forms;

class Grid {
    Cell** cells;
    int size;

    int* top_clues;
    int* bottom_clues;
    int* left_clues;
    int* right_clues;
public:
    Grid(int);
    void fill_grid(DataGridView^);

    Grid(const Grid&);
    Grid& operator=(const Grid&);

    Cell* operator[](int);

    int get_size();

    void set_top_clues(DataGridView^);
    void set_bottom_clues(DataGridView^);
    void set_left_clues(DataGridView^);
    void set_right_clues(DataGridView^);

    void set_cell_to(int, int, int);

    bool is_filled();
    bool is_solved();
    bool is_solvable();

    void remove_extra_possibilities();
    void remove_single_possibility();
    bool solve_basic_clues();
    bool solve();

    void display(DataGridView^);

    ~Grid();
};
