#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int S = 1, T = 2;

    char table[2][3][4] ={"aT", "", "",
                          "", "+ST", "#"};  // parse table
    
    int size[2][3] = {2,0,0,
                      0,3,1};  // size of the parse table

    char str[30], stack[30];
    int str_top, stack_top, row, column;

    printf("Enter the string: ");
    scanf("%s", str);
    strcat(str, "$");

    stack_top = 0;
    str_top = 0;

    stack[stack_top++] = '$';   // stack init -> $S
    stack[stack_top] = 'S';

    printf("\nStack\t\tInput\n");

    while( (stack[stack_top] != '$') || (str[str_top] != '$') )
    {
        for(int i=0; i<=stack_top; i++) printf("%c", stack[i]);
        printf("\t\t");
        for(int i=str_top; i<strlen(str); i++) printf("%c", str[i]);
        printf("\n");

        if(stack[stack_top] == str[str_top])  // if both the string top and stack top are same pop at both
        {
            stack_top--;
            str_top++;

            if(stack_top >= 30 || str_top > strlen(str))
            {
                printf("\nStack error\n");
                exit(1);
            }

        }

        switch (str[str_top])  // getting column of parse table
            {
            case 'a': column = 0; break;
            case '+': column = 1; break;
            case '$': column = 2; break;
            default: column = 3 ;break;
            }

        if(column == 3)
        {
            printf("\nError in string\n");
            exit(1);
        }

        switch (stack[stack_top])  // getting row of the parse table
        {
            case 'S': row = 0; break;
            case 'T': row = 1; break;
            default: row = 2; break;
        }

        if(row == 2)
        {
            printf("\nError in elements of stack\n");
            exit(1);
        }
        
        if(strcmp(table[row][column], "\0") == 0)
        {
            printf("\nGiven string is not part of grammer\n");
            exit(0);
        }

        else
        {
            for(int i = size[row][column] - 1; i >= 0; i--)
            {
                stack[stack_top] = table[row][column][i];
                stack_top += 1;

                if(stack_top >= 30)
                {
                    printf("\nError in stack size\n");
                    exit(1);
                }
            }

            stack_top -= 1;
        }

        if(stack[stack_top] == '#') stack_top--;
    }

    //printf("\nPriting lol:\n");
    for(int i=0; i<=stack_top; i++) printf("%c", stack[i]);
    printf("\t\t");
    for(int i=str_top; i<strlen(str); i++) printf("%c", str[i]);
    printf("\n");

    printf("\nTop: stack - %c | str - %c\n", stack[stack_top], str[str_top]);

    if(stack[stack_top] == str[str_top])
     printf("\nSuccess");

    return 0;
}