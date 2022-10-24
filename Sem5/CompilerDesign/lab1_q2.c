/*
       Compiler Design 
       @Author : Anirudh Sathish
       @Roll No : CS20B1125
       2. Write a simple C code to remove spaces and new line 
       enter characters and comment lines of a given input C program
       Input: A text file with a C program
       Output: A text file of the above C program without any space
       between words and the whole program is in a single line.
       All comments to be removed from the input.
*/

// Defining the header files 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


/* Function to deal with comments , both single and multi line comm
ents */
int foundbackslash(char *msg , int i , long length)
{
    // Intialiing variables 
    int index = i;
    int front = index+1;
    int j ; 
    index++;
    front++;
    int change;

    // Dealing with the case of single line comments 
    if(msg[index] == '/')
    {
        //Comments come to end when line ends 
        // So keeping track of end of line 
        while(msg[index]!= 10)
        {
            index++;
        }
        return index;
    }

    // Dealing with the case of multiline comments 
    else if(msg[index] =='*')
    {
        index++;
        front++;
        change = 0 ;
        
        //Dealing with end of multiline comments
        while(msg[index]!='*' || msg[front] != '/')
        {
            if(msg[front] == '/')
            {
                printf("End");
                return index;
            }

            index++;
            front++;
            change = 1 ;
        }
        
        // Useful To check if end of line was found or not
        if(change == 1)
        {
            if(msg[index] == '*' && msg[front] =='/')
            {
                index = index+2;
                return index;
            }
        }
        
        return index;
    }
    return i; 
}


// Function to deal with spaces , end lines and comments 
char *removeSpace(char *msg , long int length)
{
    // Initalising array which has to hold the resultant
    char *newMsg;
    if(length>0)
    {
        newMsg = malloc(length*sizeof(char));
    }
    int i = 0 ;
    int j = 0 ;

    // Checking for end of line and blank space
    // While parsing  
    for(; i < length; i++)
    {
        if(msg[i] != ' ')
        {
            if(msg[i] == '/')
            {
                // Noticed a black slash
                i = foundbackslash(msg, i,length);
            }
            if(msg[i] != 10)
            {
                newMsg[j] = msg[i];
                j++;
            }
        }
    }
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
    // Replace containscodewithcoments.txt by any textfile neccesary
    // Currently ensure , to keep it in the same folder
    // as the source code 
    // This can be overcome by mentioning path 
    ptr = fopen("containscodewithcomments.txt", "r");
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

    char *outputString;
    outputString= removeSpace(inputString,num);
    printf(outputString);
    printf("\n\n***************************************** \n");

    // To store the processed text in a text file 
    FILE *myPtr;
    myPtr = fopen("output_q2.txt","w");
    fprintf(myPtr,outputString);
    fclose(myPtr);
 
    return 0;
}