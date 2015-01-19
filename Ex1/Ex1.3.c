#include <stdio.h>
int main()
{
int n,last,num=0;
 printf("Please enter a positive integer:\n");
 scanf("%d",&n);
if (n<=0)
	printf("You entered wrong input!\n");
else 
	{

printf("The number you entered: %d\n",n);
 last=n%10;
printf("The last digit of your number: %d\n",last);
while(n>0)
		{
	n/=10;
	num++;

		}
printf("The number of digits in your number: %d\n",num);
	}
return 0;
}
