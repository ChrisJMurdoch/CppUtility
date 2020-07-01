
#include <utility/matrix.hpp>

Matrix::Matrix(int rows, int cols) : data(rows*cols)
{
    this->rows = rows;
    this->cols = cols;
}

float *Matrix::operator[](int row)
{
    return &data[cols*row];
}

int Matrix::size()
{
    return rows*cols;
}
