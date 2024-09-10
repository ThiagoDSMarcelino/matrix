#include <stdlib.h>
#include <stdexcept>
#include <iostream>

#include "matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;

    this->length = rows * cols;

    this->data = (double *)malloc(sizeof(double) * this->length);

    for (size_t i = 0; i < this->length; i++)
    {
        this->data[i] = 0;
    }
}

Matrix::Matrix(const Matrix *other)
{
    this->rows = other->rows;
    this->cols = other->cols;
    this->length = other->length;
    this->data = (double *)malloc(sizeof(double) * this->length);
    std::copy(other->data, other->data + this->length, this->data);
}

Matrix::~Matrix()
{
    free(this->data);
}

size_t Matrix::get_size() const
{
    return this->length;
}

size_t Matrix::get_rows() const
{
    return this->rows;
}

size_t Matrix::get_cols() const
{
    return this->cols;
}

double Matrix::get(size_t row, size_t col) const
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return this->data[row * this->cols + col];
}

void Matrix::set(size_t row, size_t col, double value)
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    this->data[row * this->cols + col] = value;
}

Matrix *Matrix::operator*(double value) const
{
    Matrix *result = new Matrix(this);

    for (size_t i = 0; i < result->length; i++)
    {
        result->data[i] *= value;
    }

    return result;
}

Matrix *Matrix::operator*(Matrix *matrix) const
{
    if (this->cols != matrix->rows)
    {
        throw std::logic_error("Invalid matrix multiplication");
    }

    Matrix *result = new Matrix(this->rows, matrix->cols);

    const size_t n = this->cols;

    for (size_t i = 0; i < result->rows; i++)
    {
        for (size_t j = 0; j < result->cols; j++)
        {
            double value = 0;

            for (size_t u = 0; u < n; u++)
            {
                value += this->get(i, u) * matrix->get(u, j);
            }

            result->set(i, j, value);
        }
    }

    return result;
}
