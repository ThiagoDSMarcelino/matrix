#include <gtest/gtest.h>

#include "matrix.h"

TEST(BaseOperations, Get)
{
    // Arrange
    const int rows = 2;
    const int cols = 2;
    const double value = 2.6;
    Matrix matrix = new Matrix(rows, cols);

    // Act
    matrix.set(1, 1, value);

    // Assert
    EXPECT_EQ(matrix.get(1, 1), value);
}
