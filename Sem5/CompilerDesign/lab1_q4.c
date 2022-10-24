/*
       Compiler Design 
       @Author : Anirudh Sathish
       @Roll No : CS20B1125
        4. Write a C program to convert a given simple mathematical
        expression into prefix notation. You can assume some simple
        conditions for input like only 3 to 4 components are there
        in the expression.
        Example = If the input string is 
        E=(X*Y)-(Z+X) 
        then the output must be E=  - * X Y + Z X.
*/

// Defining the header files 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// struct for linked list
struct list
{
    int data;
    struct list *next;
}
*top = NULL, *node;

// For pushing value into stack 
void push(int p)
{
    node = (struct list *)malloc(sizeof(struct list));
    node->data = p;

    if (top == NULL)
    {
        node->next = NULL;
        top = node;
    }
    else
    {
    node->next = top;
    top = node;
    }
}

// To pop from a stack 
void pop()
{
    if (top == NULL)
    {
        printf("Underflow ");
    }
    else
    {
        top = top->next;
        free(node);
        node = top;
    }
}


// Defining a priority order for the operators
int priority (char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == ')')
    {
        return 0;
    }
}


// Function to find the prefix expression 
void prefix(char *a, char *b)
{
    int j = 0;
    int i ;
    int term1 = -1;
    int term2;

    // Parsing through the expression 
    for ( i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^')
        {
            term2 = priority(a[i]);
            if (top != NULL)
                term1 = priority(top->data);
            if (term1 < term2)
                push(a[i]);
            else if (term1 == term2)
            {
                if (term1 == 3)
                {
                    b[j] = a[i];
                    j++;
                }
            else
                push(a[i]);
            }
            else
            {
                while (term2 < term1 && top != NULL)
                {
                    b[j] = top->data;
                    pop();
                    j++;
                    if (top != NULL)
                        term1 = priority(top->data);
                }
                push(a[i]);
            }
        }
        else if (a[i] == ')')
            push(a[i]);
        else if (a[i] == '(')
        {
            while (top->data != ')')
            {
                b[j] = top->data;
                j++;
                pop();
            }
            pop();
        }
        else
        {
            b[j] = a[i];
            j++;
        }
    }
    b[j] = '\0';
}


// Function to reverse the given expression 
void reverse(char *str, char *temp)
{
    int j = 1;
    int i ;
    temp[0] = ')';
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        temp[j] = str[i];
        j++;
    }
    temp[j] = '(';
    temp[j + 1] = '\0';
}

int main()
{
    char string[100], temp [100];

    printf("Enter the String:- ");
    scanf("%s", string);

    // Reversing the expression 
    reverse(string, temp);
    // Finding the prefix equivalent 
    prefix(temp, string);

    printf("The prefix notation of the string is \n");
    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }

    return 0;
}