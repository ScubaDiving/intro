#include <stdio.h>
int main(){
int x1,y1,z1,x2,y2,z2,d,out1,out2,out3;

printf("Please enter three coefficients for the first vector, by the order (x,y,z):\n");
scanf("%d",&x1);
scanf("%d",&y1);
scanf("%d",&z1);

printf("Please enter three coefficients for the second vector, by the order (x,y,z):\n");
scanf("%d",&x2);
scanf("%d",&y2);
scanf("%d",&z2);

printf("For dot-product select 1\n For cross-product select 2\n");
scanf("%d",&d);

if(d==1)
	{ //DOT PRODUCT
	out1=x1*x2+y1*y2+z1*z2;
	printf("The dot product of the two vectors is: %d\n",out1);
	}
else if(d==2){ //CROSS PRODUCT
out1=y1*z2-z1*y2;//X
out2=z1*x2-x1*z2;//Y
out3=x1*y2-y1*x2;//Zprintf("The cross product of the two vectors is:\n");
printf("X-axis coefficient: %d\n",out1);
printf("Y-axis coefficient: %d\n",out2);
printf("Z-axis coefficient: %d\n",out3);

}
return 0;
}
