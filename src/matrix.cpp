#include <stdlib.h>
#include <stdexcept>

#include "matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;

    size_t length = rows * cols;

    this->data = (double *)malloc(sizeof(double) * length);

    for (size_t i = 0; i < length; i++)
    {
        this->data[i] = 0;
    }
}

Matrix::Matrix(size_t rows, size_t cols, double *data)
{
    throw std::logic_error("Function not yet implemented");
}

Matrix::Matrix(size_t rows, size_t cols, double **data)
{
    throw std::logic_error("Function not yet implemented");
}

Matrix::~Matrix()
{
    free(this->data);
}

size_t Matrix::getSize() const
{
    return this->rows * this->cols;
}

double Matrix::at(size_t row, size_t col)
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return this->data[row * col];
}

void Matrix::set(size_t row, size_t col, double value)
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    this->data[row * col] = value;
}
