#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
private:
    double *data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, double *data);
    Matrix(size_t rows, size_t cols, double **data);
    ~Matrix();

    size_t getSize() const;
    double at(size_t row, size_t col);
    void set(size_t row, size_t col, double value);
};

#endif // MATRIX_H