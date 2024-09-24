#include <gtest/gtest.h>

#include "matrix.h"

TEST(Constructors, Zero)
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

TEST(Transpose, Transpose)
{
    // Arrange
    Matrix matrix = {
        {1, 2, 3},
        {4, 5, 6}};

    Matrix expected = {
        {1, 4},
        {2, 5},
        {3, 6}};

    // Act
    Matrix actual = matrix.transpose();

    // Assert
    EXPECT_EQ(matrix.get_rows(), actual.get_cols());
    EXPECT_EQ(matrix.get_cols(), actual.get_rows());
    EXPECT_EQ(expected, actual);
}

TEST(Multiplication, TimesValue)
{
    // Arrange
    const double times = 2.6;
    Matrix matrix = {
        {1, 2},
        {3, 4}};

    Matrix expected = {
        {1 * times, 2 * times},
        {3 * times, 4 * times}};

    // Act
    Matrix actual = matrix * times;

    // Assert
    EXPECT_TRUE(actual == expected);
}

TEST(Multiplication, TimesMatrix)
{
    // Arrange
    Matrix A = {
        {0, 1, 2},
        {1, 2, 3}};

    Matrix B = {
        {0, 0},
        {1, 2},
        {2, 4}};

    Matrix expected = {
        {5, 10},
        {8, 16}};

    // Act
    Matrix actual = A * B;

    // Assert
    EXPECT_TRUE(actual == expected);
}