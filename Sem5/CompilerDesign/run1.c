#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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
            if(msg[i] != 10)
            {
                //printf("%c",msg[i]);
                newMsg[j] = msg[i];
                j++;
            }
        }
    }
    printf("%s",newMsg);
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