#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 'A'+255;

    printf("%c", c);
    return 0;
}
/**OverFlow Message In Compile Time and Prints @ instead of 'A'*/
