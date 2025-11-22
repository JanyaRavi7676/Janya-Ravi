#include <stdio.h>
point()
{
    int var = 10;
    int *ptr;
  
  *ptr = &var;
   
     printf("Value at ptr = %d \n", ptr);
    printf("Value at var = %d \n", var);
    printf("Value at *ptr = %d \n", *ptr);
}

int main()
{
point();
}