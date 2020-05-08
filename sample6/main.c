#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv)
{
 if (argc != 2)
 {
     printf("usage:%s filename",argv[0]);
 }
 else
 {
     FILE*file = fopen(argv[1],"r");
     if (file==NULL)
        printf("Could not open file\n");
     else
     {
         int x;
         while((x=fgetc(file))!= EOF)
            printf("%c",x);
         fclose(file);
     }
 }
}
