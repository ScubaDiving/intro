#include <stdio.h>
#include <string.h>

void swap(char *str);

int main() {

    char str[80];
    gets(str);
    swap(str);
    printf("%s\n",str);
    return 0;
}

void swap(char* str) { //Decleraion
    long unsigned int len=strlen(str); //length of current string
    static int j=0; //STATIC var for running index
    char temp;
    if(j<=len/2){
        temp=str[0];
        str[0]=str[len-j-1];
        str[len-j-1]=temp; //swapping first and last chars
        j++;
        str+=1;
        swap(str); //call for next set of chars to swap
    }
    else{
        return;
    }



}