#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    printf("\nEnter expressions of format <operand>=<operand><operator><operand>: (enter EXIT to stop entering)\n");

    char expressions[5][MAX]; // max of 20 expressions can be entered....change this to insert more
    int i = 0;

    while (1)
    {
        printf("\nExpression %d: ", i + 1);
        scanf("%s", expressions[i++]);

        if (strcmpi(expressions[i - 1], "exit") == 0 || i >= MAX)
            break;
    }

    /*
    expressions in format:
    [0]:<operand>
    [1]:=
    [2]:<operand>
    [3]:<operator>
    [4]:<operand>
    */

    char op;

    printf("\nGeneral three address format of assembly:\n");

    for (int j = 0; j < i; j++)
    {
        if (strcmpi(expressions[j], "exit") == 0)
            break;

        op = expressions[j][3];

        printf("MOV R0,%c\n", expressions[j][2]);
        printf("MOV R1,%c\n", expressions[j][4]);

        switch (op)
        {
        case '+':
            // a = b+c
            printf("ADD R0,R1\n");
            break;

        case '-':
            // a = b-c
            printf("SUB R0,R1\n");
            break;

        case '*':
            // a = b*c
            printf("MUL R0,R1\n");
            break;

        case '/':
            // a = b/c
            printf("DIV R0,R1\n");
            break;

        default:
            printf("Error\n\n");
            exit(0);
        }

        printf("MOV %c,R0\n\n", expressions[j][0]);
    }

    printf("---------------\nIn NASM syntax:\n");

    for (int j = 0; j < i; j++)
    {
        if (strcmpi(expressions[j], "exit") == 0)
            break;

        op = expressions[j][3];

        printf("MOV eax,%c\n", expressions[j][2]);
        printf("MOV ebx,%c\n", expressions[j][4]);

        switch (op)
        {
        case '+':
            // a = b+c
            printf("ADD eax,ebx\n");
            break;

        case '-':
            // a = b-c
            printf("SUB eax,ebx\n");
            break;

        case '*':
            // a = b*c
            printf("MUL ebx\n");
            break;

        case '/':
            // a = b/c
            printf("DIV ebx\n");
            break;

        default:
            printf("Error in operator encountered apart from +-*/\n\n");
            exit(0);
        }

        printf("MOV %c,eax\n\n", expressions[j][0]);
    }

    return 0;
}