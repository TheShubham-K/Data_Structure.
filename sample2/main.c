#include <stdio.h>
#include <conio.h>

int main()
{
   int Age;
   char MaritalStatus,Gender;
   printf("Enter Marital Status, Gender,Age: ");
   scanf("%c,%c,%d",&MaritalStatus,&Gender,&Age);
   if(MaritalStatus=='m')
   {
       printf("You can't Marry!");
   }
   else if(MaritalStatus=='u')
   {
       if(Gender=='m')
       {
           if(Age>=21)
           {
               printf("You can Marry!");
           }
           else
           {
               printf("You can't Marry!");
           }
       }
       else if (Gender=='f')
       {
           if(Age>=18)
           {
               printf("You can Marry!");
           }
           else
            printf("you can't Marry!");
       }
       else
        printf("Invalid Input Gender");
   }
   else
    printf("Invalid Input Marital Status!!");

}
