#include <gtest/gtest.h>

#include "matrix.h"

TEST(Matrix, Constructors)
{
    // Arrange
    const int rows = 2;
    const int cols = 4;

    // Act
    Matrix matrix = new Matrix(rows, cols);

    // Assert
    EXPECT_EQ(matrix.get_rows(), rows);
    EXPECT_EQ(matrix.get_cols(), cols);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            EXPECT_EQ(matrix.get(i, j), 0);
        }
    }
}

TEST(Matrix, Get)
{
    // Arrange
    const int rows = 2;
    const int cols = 2;
    const double value = 2.6;

    // Act
    Matrix matrix = new Matrix(rows, cols);
    matrix.set(1, 1, value);

    // Assert
    EXPECT_EQ(matrix.get(1, 1), value);
}