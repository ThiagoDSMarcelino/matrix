#include <gtest/gtest.h>

#include "matrix.h"

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