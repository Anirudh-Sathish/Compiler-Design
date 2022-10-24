
// Anirudh Sathish
// CS20B1125 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<ctype.h>

typedef struct
{ 
    char var[10];
    int state;
}
reg_d;


void substring(char exp[],int start,int end)
{ 
    int i;
    int j = 0;
    char dup[10]="";
    for(i=start;i<end; i++)
        dup[j++]=exp[i];
        dup[j]='0';
        strcpy(exp,dup);
}

reg_d register_descriptor[10];
// Function to check if register is avaiable 
int getReg(char var[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(register_descriptor[i].state == 0)
        {
            strcpy(register_descriptor[i].var,var);
            break;
        }
    }
    return(i);
}
void getLoc(char expression[],char v[])
{ 
    int i;
    int j=0;
    char loc[10]="";
    for(i=0;expression[i]!='\0';i++)
    if(isalpha(expression[i]))
    {
        loc[j++]=expression[i];
    }
    else
        break;
    strcpy(v,loc);
}




void main()
{ 
    int i,j,k;
    int reg,count,flag=0;

    char input[10][10];
    char loc[10][10];
    char fstr[10];
    char operator;
    

    printf("\nEnter the Three Address Code:\n");
    printf("!! Enter end to come out of the console \n ");
    for(i=0;;i++)
    {
        gets(input[i]);
        if(strcmp(input[i],"end") == 0)
        {
            break;
        }
    }
    printf("\nThe Equivalent Assembly Code is:\n");

    for(j=0;j < i;j++)   
    {
        getLoc(input[j],loc[count++]);
        strcpy(fstr,loc[count-1]);
        substring(input[j],strlen(loc[count-1])+1,strlen(input[j]));
        
        getLoc(input[j],loc[count++]);
        reg = getReg(loc[count-1]);
        
        if(register_descriptor[reg].state == 0)
        {
            printf("\nMOV R%d,%s",reg,loc[count-1]);
            register_descriptor[reg].state = 1;
        }
        
        operator = input[j][strlen(loc[count-1])];
        substring(input[j],strlen(loc[count-1])+1,strlen(input[j]));
        getLoc(input[j],loc[count++]);
        
        switch(operator)
        {
            case '+':
                printf("\nADD");
                break;
            case '-':
                printf("\nSUB");
                break;
            case '*':
                printf("\nMUL");
                break;
            case '/':
                printf("\nDIV");
                break;
        }

        flag=1;
        for(k=0;k<=reg;k++)
        { 
            if(strcmp(register_descriptor[k].var,loc[count-1])==0)
            {
                printf("R%d, R%d",k,reg);
                register_descriptor[k].state=0;
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf(" %s ,R%d",loc[count-1],reg);
            printf("\nMOV %s,R%d",fstr,reg);
        }
        strcpy(register_descriptor[reg].var,loc[count-3]);
    }
}