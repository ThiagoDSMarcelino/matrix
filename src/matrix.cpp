#include <stdexcept>

#include "matrix.h"
#include "invalid_matrix_size.h"

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

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list)
{
    this->rows = list.size();
    this->cols = list.begin()->size();
    this->length = this->rows * this->cols;
    this->data = (double *)malloc(sizeof(double) * this->length);

    size_t index = 0;
    for (const auto &row : list)
    {
        for (const auto &value : row)
        {
            this->data[index] = value;
            index++;
        }
    }
}

Matrix::~Matrix()
{
    free(this->data);
}

size_t Matrix::get_rows() const
{
    return this->rows;
}

size_t Matrix::get_cols() const
{
    return this->cols;
}

void Matrix::define(size_t row, size_t col, double value)
{
    this->data[row * this->cols + col] = value;
}

double Matrix::access(size_t row, size_t col) const
{
    return this->data[row * this->cols + col];
}

double Matrix::get(size_t row, size_t col) const
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return this->access(row, col);
}

Matrix Matrix::transpose() const
{
    Matrix transposed = new Matrix(this->cols, this->rows);

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            double value = this->access(i, j);
            transposed.define(j, i, value);
        }
    }

    return transposed;
}

void Matrix::set(size_t row, size_t col, double value)
{
    if (row >= this->rows || col >= this->cols)
    {
        throw std::out_of_range("Index out of bounds");
    }

    this->define(row, col, value);
}

Matrix Matrix::operator*(double value) const
{
    Matrix result(this);

    for (size_t i = 0; i < result.length; i++)
    {
        result.data[i] *= value;
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &matrix) const
{
    if (this->cols != matrix.rows)
    {
        throw invalid_matrix_size();
    }

    Matrix result(this->rows, matrix.cols);

    const size_t n = this->cols;

    for (size_t i = 0; i < result.rows; i++)
    {
        for (size_t j = 0; j < result.cols; j++)
        {
            double value = 0;

            for (size_t u = 0; u < n; u++)
            {
                value += this->get(i, u) * matrix.get(u, j);
            }

            result.set(i, j, value);
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix &matrix) const
{
    if (this->rows != matrix.rows || this->cols != matrix.cols)
    {
        return false;
    }

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->get(i, j) != matrix.get(i, j))
            {
                return false;
            }
        }
    }

    return true;
}
