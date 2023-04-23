#pragma once
#include "Puzzle.h"

using namespace System;
using namespace Windows::Forms;

int** create_matrix(int);

bool create_puzzle(int**, int, int);

void create_top_clues(int**, int, DataGridView^);
void create_bottom_clues(int**, int, DataGridView^);
void create_left_clues(int**, int, DataGridView^);
void create_right_clues(int**, int, DataGridView^);

void delete_matrix(int**, int);
