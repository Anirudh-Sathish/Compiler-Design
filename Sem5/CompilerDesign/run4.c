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

void prefix(char *a, char *b)
{
    int j = 0;
    int i ;
    int term1 = -1;
    int term2;

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

    reverse(string, temp);
    prefix(temp, string);

    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }

    return 0;
}