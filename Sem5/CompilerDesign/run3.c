#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *tokenize(char *msg , long int length)
{
    char *newMsg;
    if(length>0)
    {
        newMsg = malloc(length*sizeof(char));
    }
    int i = 0 ,j = 0 ,highest_len = 0, len ,count = 0 ;
    for(; i < length; i++)
    {
        len = 0 ;
        while(msg[i] != ' ' && i < length)
        {
            len++;
            i++;
        }
        if(msg[i] == ' ')
        {
            count++;
        }
        if(len>highest_len)
        {
            highest_len = len;
        }
        
    }
    printf("The highest len is %d \n",highest_len);
    printf("The total number is %d \n",len);

    char *resultant;
    int totalSize = highest_len*len;
    if(totalSize > 0)
    {
        resultant = malloc(totalSize*(sizeof(char)));
    }
    int t = 0 ;
    if(t <length)
    {
        for (i = 0; i < len; i++)
        {
            printf("The index is %d \n",i );
            for ( j = 0; j < highest_len; j++)
            {
                if(msg[t] != ' ' && msg[t] != 10)
                {
                    resultant[i*highest_len+j] = msg[t];
                    printf("%c",resultant[i*highest_len+j]);
                    printf("%d ",j);
                    t++;
                }
                else
                {
                    t++;
                    break;
                }            
            }
        }
    }
    /*printf("\n Final resultant \n");
    for (i = 0; i < len; i++)
    {
        printf("The index is %d \n",i );
        for ( j = 0; j < highest_len; j++)
        {
            printf("%c",resultant[i*highest_len+j]);
        }
    }*/
    printf("\n");
    printf(resultant);
    
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

    printf(text);

    char *tokenized_text;
    //tokenized_text = tokenize(text,numbytes);
    //printf(text);
 
    return 0;
}