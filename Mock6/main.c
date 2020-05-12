#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum {india, is=7, GREAT};
    printf("%d %d", india, GREAT);
    return 0;
}

/**output = 0 8*/

