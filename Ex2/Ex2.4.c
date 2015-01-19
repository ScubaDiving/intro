#include <stdio.h>
int main()

{
   char digits[16] =     //all possible outputs
	 {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

   int output[64];  //number to output
   long int num;    //number to conver
   int next_digit, base, i=0;

   scanf("%d",&base);
   scanf("%ld",&num);

   /* convert to the indicated base */
   while (num != 0)
   {
	 output[i] = num % base;
	 num /= base;
	 i++;
   }

   //print the result in reverse order
   i--;  // go back to last index in the array 
   while(i>=0) // go backwards through array 
   {
	 printf("%c",digits[output[i]]);
   i--;}
   printf("\n");
return 0;}
