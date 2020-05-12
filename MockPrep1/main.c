#include <stdio.h>
#include <stdlib.h>

int main()
{
    int const a = 5;

    a++;
    printf("%d", a);
    return 0;
}

/**Compile Error*/
