#include <stdio.h>
	int main()
{
	int n=0,tmp,i=1,octal=0,hex=0;
	printf("Enter a positive number:\n");
	scanf("%d",&n);
	printf("Decimal number: %d\n",n);
	printf("Hex number: %x\n",n);
	printf("Octal number: %o\n",n);
	return 0;
}
