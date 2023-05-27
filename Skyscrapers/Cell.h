#pragma once

#include <vector>
using namespace std;

class Cell {
    vector<int> possibilities;
    int value;

public:
    Cell() = default;
    Cell(int);

    int get_value();
    vector<int> get_possibilities();

    bool contain_possibility(int);

    void set_value(int);
    void remove_possibility(int);
    void left_possibility(int);
};