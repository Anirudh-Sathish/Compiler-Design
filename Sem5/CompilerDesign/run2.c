#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int foundbackslash(char *msg , int i , long length)
{
    int index = i;
    int front = index+1;
    int j ; 
    index++;
    front++;
    int change;
    if(msg[index] == '/')
    {
        while(msg[index]!= 10)
        {
            index++;
        }
        return index;
    }
    else if(msg[index] =='*')
    {
        index++;
        front++;
        change = 0 ;
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

char *removeSpace(char *msg , long int length)
{
    char *newMsg;
    if(length>0)
    {
        newMsg = malloc(length*sizeof(char));
    }
    int i = 0 ;
    int j = 0 ;
    for(; i < length; i++)
    {
        if(msg[i] != ' ')
        {
            if(msg[i] == '/')
            {
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
    FILE    *textfile;
    char    *text;
    long int   numbytes;
     
    textfile = fopen("containscodewithcomments.txt", "r");
    if(textfile == NULL)
        return 1;
     
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);  
 
    text = (char*)calloc(numbytes, sizeof(char));   
    if(text == NULL)
        return 1;
 
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    text = removeSpace(text,numbytes);
    printf(text);
 
    return 0;
}