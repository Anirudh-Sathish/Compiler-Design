
// @Author : Anirudh Sathish 
// @RollNo : CS20B1125
// @ Task : Recognising the given languages 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int language1Test(char *msg , int msgLen)
{
    int i = 0 ;
    int state ;

    // Initalise state to 1 
    // All strings start at 1 
    state = 1;
    char curr ;

    while(msg[i] != '\0')
    {
        switch(state)
        {
            case 1 :
                curr = msg[i];
                if(curr == 'a')
                {
                    state = 1;
                }
                else
                {
                    state = 2;
                }
                i++;
                break;
            case 2:
                state = 2;
                i++;
                break;
        }
    }
    if(state == 1)
    {
        printf("String accepted by Language a* \n");
        return 1 ;
    }
    else
    {
        printf("String not accepted by Language a* \n");
        return 0;
    }
}

int lanuage2Test(char *msg , int msgLen)
{
    int i = 0 ;
    int state ;

    // Initalise state to 1 
    // All strings start at 1 
    state = 1;
    char curr ;

    while(msg[i] != '\0')
    {
        switch(state)
        {
            case 1 :
                curr = msg[i];
                if(curr == 'a')
                {
                    state = 1;
                }
                else if(curr == 'b')
                {
                    state = 2;
                }
                else
                {
                    state = 3;
                }
                i++;
                break;
            case 2:
                curr = msg[i];
                if(curr == 'b')
                {
                    state = 2;
                }
                else
                {
                    state = 3;
                }
                i++;
                break;
            case 3:
                state = 3;
                i++;
                break;
        }
    }
    if(state == 2)
    {
        printf("String accepted by Language a*b+ \n");
        return 1 ;
    }
    else
    {
        printf("String not accepted by Language a*b+ \n");
        return 0;
    }
}

int language3Test(char *msg , int msgLen)
{
    int i = 0 ;
    int state ;

    // Initalise state to 1 
    // All strings start at 1 
    state = 1;
    char curr ;

    while(msg[i] != '\0')
    {
        switch(state)
        {
            case 1 :
                curr = msg[i];
                if(curr == 'a')
                {
                    state = 2;
                }
                else
                {
                    state = 5;
                }
                i++;
                break;
            case 2:
                curr = msg[i];
                if(curr == 'b')
                {
                    state = 3;
                }
                else
                {
                    state = 5;
                }
                i++;
                break;
            case 3:
                curr = msg[i];
                if(curr == 'b')
                {
                    state = 4;
                }
                else
                {
                    state = 5;
                }
                i++;
                break;
            case 4:
                state = 5;
                i++;
                break;
            case 5 :
                state = 5;
                i++;
                break;
        }
    }
    if(state == 4)
    {
        printf("String accepted by Language abb \n");
        return 1 ;
    }
    else
    {
        printf("String not accepted by Language abb \n");
        return 0;
    }
}



int main()
{
    int msgLen;
    printf("Enter the length of the string u want to test for \n");
    scanf("%d",&msgLen);
    char *msg;
    
    if(msgLen > 0)
    {
        msg = malloc(msgLen*sizeof(char));
    }
    printf("Enter the string to test \n");
    scanf("%s",msg);

    // Dealing For the language case 1
    int boo = language1Test(msg,msgLen);

    // Dealing for the language case 2 
    int boo2 = lanuage2Test(msg,msgLen);

    // Dealing for the language case 3
    int boo3 = language3Test(msg,msgLen);
    


    return 0;
    

     


}