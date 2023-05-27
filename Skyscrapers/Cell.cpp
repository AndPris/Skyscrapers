#include "cell.h"
#include <iostream>

Cell::Cell(int size) {
    for (int i = 0; i < size; i++)
        possibilities.push_back(i + 1);

    value = 0;
}

int Cell::get_value() {
    return value;
}
vector<int> Cell::get_possibilities() {
    return possibilities;
}


bool Cell::contain_possibility(int possibility) {
    if (find(possibilities.begin(), possibilities.end(), possibility) != possibilities.end())
        return true;

    return false;
}

void Cell::set_value(int value) {
    this->value = value;
}

void Cell::remove_possibility(int value) {
    if (contain_possibility(value))
        possibilities.erase(find(possibilities.begin(), possibilities.end(), value));
}

void Cell::left_possibility(int value) {
    possibilities.clear();
    possibilities.push_back(value);
}