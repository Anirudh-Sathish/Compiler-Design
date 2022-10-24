#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct registers
{
    char location[10];
    int alive;
};

struct registers systemRegisters[10];


int main()
{
    // Take the input for the 3 address code 
    char ThreeAddress[10][10];
    printf("Enter the three address basic code \n");
    int i ;
    for(i = 0 ; ; i++)
    {
        gets(ThreeAddress[i]);
        if(strcmp(ThreeAddress[i],"exit") ==0)
        {
            break;
        }
    }
}