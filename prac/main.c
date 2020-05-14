#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%[^\n]", &s);

    printf("Hello, world!\n");
    printf("%s", s);
    return 0;
}
