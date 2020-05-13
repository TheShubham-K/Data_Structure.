#include <stdio.h>

int fibonacci(int i) {

   if(i == 0) {
      return 0;
   }

   if(i == 1) {
      return 1;
   }
   return fibonacci(i-1) + fibonacci(i-2);
}

int  main() {

   int i,n;
   printf("Enter n:");
   scanf("%d",&n);

   for (i = 0; i < n; i++) {
      printf("%d\t\n", fibonacci(i));
   }

   return 0;
}
