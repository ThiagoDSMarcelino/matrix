#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
private:
    double *data;
    size_t rows;
    size_t cols;
    size_t length;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix *other);
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    ~Matrix();

    size_t get_rows() const;
    size_t get_cols() const;

    double get(size_t row, size_t col) const;
    void set(size_t row, size_t col, double value);

    Matrix operator*(double value) const;
    Matrix operator*(const Matrix &matrix) const;

    bool operator==(const Matrix &matrix) const;
};

#endif // MATRIX_H