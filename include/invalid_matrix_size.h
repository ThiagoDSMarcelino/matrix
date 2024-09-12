#ifndef INVALID_MATRIX_SIZE_H
#define INVALID_MATRIX_SIZE_H

#include <exception>

struct invalid_matrix_size : public std::exception
{
};

#endif // INVALID_MATRIX_SIZE_H