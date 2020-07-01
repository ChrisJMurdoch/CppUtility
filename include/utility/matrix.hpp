
#pragma once

#include <vector>

class Matrix
{
private:
    std::vector<float> data;
    int rows, cols;

public:
    Matrix(int rows, int cols);

    /** Return pointer to sub-array */
    float *operator[](int row);

    /** Number of members in matrix */
    int size();
};
