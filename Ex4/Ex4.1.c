#include <stdio.h>
#include <stdlib.h>

int isDown(int* input,int size);  //returns 1 for decending and 0 for not

int main(){

    double temp;
int i,size;
int* input; //array of numbers

scanf("%d",&size);

input=(int*)malloc(sizeof(int)*size);

for (i = 0; i < size; i++) {
        scanf("%lf", &temp);    //SCAN
        if (temp - (int) temp)
            return printf("Error\n");  //INT CHECK
       input[i] = (int) temp;
    }

  if(isDown(input,size))
    printf("The numbers are decending series\n");
  else 
    printf("The numbers are not decending series\n");

  return 0;
}

int isDown(int* input, int size){

    if(size==1)
        return 1;
    else
        return input[0]>input[1] && isDown(++input,--size); //will return 0 if bigger then next one and terminate,
    //or will continue checking




}
