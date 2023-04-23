#include "Generator.h"
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int** create_matrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    return matrix;
}

bool create_puzzle(int** matrix, int size, int index) {
    if (index == size * size) { //the matrix is filled
        return true;
    }

    //position of the next element to be filled
    int col = index % size;
    int row = index / size;

    //if can_use[i] == true, then number i+1 can be used
    bool* can_use = new bool[size];
    for (int i = 0; i < size; i++) {
        can_use[i] = true;
    }

    //exclude previous elements from this row and column
    for (int i = 0; i < col; i++) {
        can_use[matrix[row][i] - 1] = false;
    }
    for (int i = 0; i < row; i++) {
        can_use[matrix[i][col] - 1] = false;
    }


    //possible elements
    vector<int> possibilities;
    for (int i = 1; i <= size; i++) {
        if (can_use[i - 1]) {
            possibilities.push_back(i);
        }
    }
    delete[] can_use;

    if (possibilities.empty()) {
        return false;
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    shuffle(possibilities.begin(), possibilities.end(), e);

    for (int i = 0; i < possibilities.size(); i++) {
        matrix[row][col] = possibilities[i];

        if (create_puzzle(matrix, size, index + 1)) {
            return true;
        }
    }

    return false;
}

void create_top_clues(int** matrix, int size, DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        int highest = matrix[0][i];
        int counter = 1;

        for (int j = 1; j < size; j++) {
            if (matrix[j][i] > highest) {
                counter++;
                highest = matrix[j][i];
            }
        }

        clues->Rows[0]->Cells[i]->Value = Convert::ToString(counter);
    }
}
void create_bottom_clues(int** matrix, int size, DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        int highest = matrix[size - 1][i];
        int counter = 1;

        for (int j = size - 2; j >= 0; j--) {
            if (matrix[j][i] > highest) {
                counter++;
                highest = matrix[j][i];
            }
        }

        clues->Rows[0]->Cells[i]->Value = Convert::ToString(counter);
    }
}
void create_left_clues(int** matrix, int size, DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        int highest = matrix[i][0];
        int counter = 1;

        for (int j = 1; j < size; j++) {
            if (matrix[i][j] > highest) {
                counter++;
                highest = matrix[i][j];
            }
        }

        clues->Rows[i]->Cells[0]->Value = Convert::ToString(counter);
    }
}
void create_right_clues(int** matrix, int size, DataGridView^ clues) {
    for (int i = 0; i < size; i++) {
        int highest = matrix[i][size - 1];
        int counter = 1;

        for (int j = size - 2; j >= 0; j--) {
            if (matrix[i][j] > highest) {
                counter++;
                highest = matrix[i][j];
            }
        }

        clues->Rows[i]->Cells[0]->Value = Convert::ToString(counter);
    }
}

void delete_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}