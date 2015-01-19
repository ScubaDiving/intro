#include <stdio.h>

int main(){
        int reverse=0,tmp,digit,check;
        double n;

        scanf("%lf",&n); 
	check=n;
        if (n<=0||check!=n) //<0 or not int
          {
          return printf("Error\n"); //BREAK
          }
        tmp=(int)n;
        while(tmp!=0)
        {
                digit=tmp%10;
                reverse=reverse*10+digit; //reversing the number
                tmp/=10;
                check=0;
        }
        if(reverse==(int)n)
                printf("The number %d is a palindrome\n",(int)n);
        else
                printf("The number %d is NOT a palindrome\n",(int)n);

return 0;
}
