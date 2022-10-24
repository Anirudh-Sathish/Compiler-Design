/*
       Compiler Design 
       @Author : Anirudh Sathish
       @Roll No : CS20B1125
       1. Write a simple C code to remove spaces and new line enter
        characters of a given input C program.
        Input: A text file with a C program
        Output: A text file of the above C program without any space
        between words and the whole program is in a single line.
*/

// Defining the header files 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Defining a function to remove spaces and new line character
// And return the character new array 
char *removeSpace(char *msg , long int length)
{
    // Intializing the new character array , which will hold the
    // resultant value
    char *newMsg;
    if(length>0)
    {
        newMsg = malloc(length*sizeof(char));
    }
    
    int i = 0 ;
    int j = 0 ;

    //Parsing through the whole text 
    for(; i < length; i++)
    {
        if(msg[i] != ' ')
        {
            if(msg[i] != 10)
            {
                // Adding the character to the resultant array
                // If it is does not have space or newline character
                newMsg[j] = msg[i];
                j++;
            }
        }
    }

    //Returning the required result
    return newMsg;
}

 
int main() 
{
    // Preparing to take text input 
    FILE *ptr;
    char *inputString;
    long int num;

    // ptr is is a FILE pointer , it points to the text of
    // the desired file 
    // Replace containscode.txt by any textfile neccesary
    // Currently ensure , to keep it in the same folder
    // as the source code 
    // This can be overcome by mentioning path 
    ptr = fopen("containscode.txt", "r");
    if(ptr == NULL)
        return 1;

    // To find the total length of the text file  
    fseek(ptr, 0L, SEEK_END);
    num = ftell(ptr);
    fseek(ptr, 0L, SEEK_SET);  

    // Initalising a string to store the text  
    inputString = (char*)calloc(num, sizeof(char));   
    if(inputString == NULL)
        return 1;

    //Reading into string , and further closing the file ptr
    fread(inputString, sizeof(char), num, ptr);
    fclose(ptr);

    printf("***************************************** \n");
    printf("Text as in file \n");
    printf(inputString);
    printf("\n***************************************** \n");
    printf("Output resultant text would be \n \n ");

    // The string to hold the reultant 
    char *outputString;
    outputString = removeSpace(inputString,num);
    printf(outputString);
    printf("\n\n***************************************** \n");
    
    // Printing out the resultant to a textfile
    FILE *myPtr;
    myPtr = fopen("output_q1.txt","w");
    fprintf(myPtr,outputString);
    fclose(myPtr);
 
    return 0;
}