#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *tokenize(char *msg , long int length)
{
    char *newMsg;

    /* Allocating Space to the character array */
    if(length>0)
    {
        newMsg = malloc(length*sizeof(char));
    }
    int i = 0 ,j = 0 ,highest_len = 0, msg_len ,count = 0 ;

    // Parsing the message 
    for(; i < length; i++)
    {
        msg_len = 0 ;
        // While there is no space or newLine 
        while(msg[i] != ' ' && i < length && msg[i] != 10)
        {
            msg_len++;
            i++;
        }
        // To find the highest length of the message 
        if(msg_len > highest_len)
        {
            highest_len = msg_len;
        }
        // To keep track of the number of words 
        if(msg_len > 0)
        {
            count++;
        }
        
    }

    // 2D Character array , that consists of all the tokens(words)
    char *resultant;

    //Setting the size of the array 
    int totalSize = highest_len*count;
    if(totalSize > 0)
    {
        resultant = malloc(totalSize*(sizeof(char)));
    }
    
    // Storing the value as a resultant array 
    int t = 0 ;
    if(t <length)
    {
        for (i = 0; i < count; i++)
        {
            msg_len = 0;
            for ( j = 0; j < highest_len;)
            {
                if(msg[t] != ' ' && msg[t] != 10)
                {
                    resultant[i*highest_len+j] = msg[t];
                    t++;
                    j++;
                    msg_len++;
                }
                else
                {
                    t++;
                    break;
                }            
            }
            if(msg_len <= 0)
            {
                i = i-1;
            }
        }
    }

    // Printing out the resultant
    printf("The resultant is \n");
    for (i = 0; i < count; i++)
    {
        printf("Stored_Array[%d] : ",i );
        for ( j = 0; j < highest_len;j++)
        {
            printf("%c",resultant[i*highest_len+j]);       
        }
        printf("\n");
    }
    return newMsg;
}
 
int main() 
{
    FILE    *textfile;
    char    *text;
    long int   numbytes;
     
    textfile = fopen("containscode.txt", "r");
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

    //printf(text);

    char *tokenized_text;
    tokenized_text = tokenize(text,numbytes);
    //printf(text);
 
    return 0;
}