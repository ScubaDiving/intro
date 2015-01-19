#include <stdio.h>

int main(){
int n,sum=0,min=0,max=0,i=0;
double avg=0;
do{
	scanf("%d",&n);
	if(i==0) //check if first iteration
	{
	max=n; //initialization - first number is set to be both
	min=n;
		if(n==0){
			  //first input is 0
        		return printf("Error\n");
			}
	}
	if(n>max&&n)
		max=n; //MAX
	if(n<min&&n)
		min=n; //MIN

	sum+=n;
	if(n)
	i++;
}while(n!=0);

avg=(double)sum/(double)i;
printf("The minimal value is: %d\n",min);
printf("The maximal value is: %d\n",max);
printf("The average is %f\n",avg);
return 0;
}
