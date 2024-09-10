#include <stdio.h>
#include <cstdlib>
#include <functional>

#include "matrix.h"

void print_matrix(const Matrix *matrix);
void fill_matrix(Matrix *matrix, std::function<double(size_t, size_t)> func);

int main()
{
    Matrix *matrix1 = new Matrix(2, 3);
    Matrix *matrix2 = new Matrix(3, 2);

    fill_matrix(matrix1, [](size_t i, size_t j) -> double
                { return i + j; });
    fill_matrix(matrix2, [](size_t i, size_t j) -> double
                { return i * j + i; });

    Matrix *result = *matrix1 * matrix2;
    Matrix *result2 = *result * 2;

    printf("Matrix 1\n");
    print_matrix(matrix1);

    printf("\nMatrix 2\n");
    print_matrix(matrix2);

    printf("\nMatrix 3\n");
    print_matrix(result);

    printf("\nMatrix 4\n");
    print_matrix(result2);

    return EXIT_SUCCESS;
}

void print_matrix(const Matrix *matrix)
{
    for (size_t i = 0; i < matrix->get_rows(); i++)
    {
        printf("| ");
        for (size_t j = 0; j < matrix->get_cols(); j++)
        {
            printf("%2.2f", matrix->get(i, j));

            if (j == matrix->get_cols() - 1)
            {
                continue;
            }

            printf(", ");
        }

        printf(" |\n");
    }
}

void fill_matrix(Matrix *matrix, std::function<double(size_t, size_t)> func)
{
    for (size_t i = 0; i < matrix->get_rows(); i++)
    {
        for (size_t j = 0; j < matrix->get_cols(); j++)
        {
            double value = func(i, j);
            matrix->set(i, j, value);
        }
    }
}