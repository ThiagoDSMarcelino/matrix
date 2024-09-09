#include <stdio.h>
#include <cstdlib>

#include "matrix.h"

int main()
{
    Matrix m(2, 3);

    printf("%2.2f\n", m.at(1, 1));

    m.set(1, 1, 2.46);

    printf("%2.2f\n", m.at(1, 1));

    return EXIT_SUCCESS;
}