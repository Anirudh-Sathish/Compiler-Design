/*               @Author :Anirudh Sathish 
                 Symbol tokeniser 
                 CS20B1125 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Creating a node for linkedList 
struct Node
{
    char token[32];
    char attr1[10];
    char attr2[30];
    struct Node *next;
};

struct Node *head = NULL ;
struct Node *curr = NULL;


char * getStringFromTxtFile(char *file_name)
{
    // Preparing to take text input 
    FILE *ptr;
    char *inputString;
    long int num;

    // ptr is is a FILE pointer , it points to the text of
    // the desired file 
    // Replace containscode.txt by any textfile neccesary
    // Currently ensure , to keep it in the same folder
    // as the source code 
    // This can be overcome by mentioning path 
    ptr = fopen("ex.txt", "r");
    if(ptr == NULL)
        return 1;

    // To find the total length of the text file  
    fseek(ptr, 0L, SEEK_END);
    num = ftell(ptr);
    fseek(ptr, 0L, SEEK_SET);  

    // Initalising a string to store the text  
    inputString = (char*)calloc(num, sizeof(char));   

    //Reading into string , and further closing the file ptr
    fread(inputString, sizeof(char), num, ptr);
    fclose(ptr);
    return inputString;
    
}

// Inserting the identifier to the token table 
void insertToSymbolTable( char *identifier , char *datatype)
{
    // Allocating memory to the node 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->token,identifier);
    strcpy(temp->attr1,identifier);
    if(head == NULL)
    {
        head->next = temp ;
        temp->next = NULL ;
        curr = temp;
    }
    else
    {
        curr->next = temp;
        temp->next = NULL ;
    }
}

char *storeToken(char *msg ,int count , int highest_len, int length)
{
    int msg_len;
    // 2D Character array , that consists of all the tokens(words)
    char *resultant;

    //Setting the size of the array 
    int totalSize = highest_len*count;
    if(totalSize > 0)
    {
        resultant = malloc(totalSize*(sizeof(char)));
    }
    
    // Storing the value as a resultant array 
    int t = 0 , i , j;
    if(t <length)
    {
        for (i = 0; i < count; i++)
        {
            msg_len = 0;
            for ( j = 0; j < highest_len;)
            {
                if(msg[t] != ' ' && msg[t] != 10)
                {
                    // Char is stored in resultant 
                    // If there is no space and 
                    // end line 
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
            // If the message length is 0 , dont count it 
            // To counter act the increment 
            // Perform a decrement 
            if(msg_len <= 0)
            {
                i = i-1;
            }
        }
    }
    return resultant;
}

// To print the tokens from the stored array
void printArrayToken(char *resultant ,int count , int highest_len)
{
    int i , j;
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
}

// Function to tokenize the textfile
void tokenizeAndSymbolTable(char *msg , long int length)
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
    
    // To store the results in an array
    char *resultant ;
    resultant = storeToken(msg,count,highest_len,length);

    // Printing out the resultant
    printArrayToken(resultant,count,highest_len);

    SymbolTableOperations(msg,length,resultant,count,highest_len);

}
 

void SymbolTableOperations(char *str, int strLen , char *token_array , int row , int column)
{
    // Maintain array consisting of header files
    char headerFiles[][30] = {"#include<stdio.h>","#include<stdlib.h>","#include<string.h>"}; 

    // Maintaing an array consisting of keywords 
    char keywords[32][20] = {"auto","break","case","char" ,"const",
                            "continue","default","do","double","else"
                            "enum","extern" ,"float","for","goto","if",
                            "int","long","register","return",
                            "short"	,"signed","sizeof","static",
                            "struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    char operators[8][5] ={'+','-','*','/','%','^',"&&","||"};

    char symb[4][3] = {',',';','{',"}"};

    //Parse the string 
    int i , j;
    // Printing out the resultant
    printf("The resultant is \n");
    for (i = 0; i < row; i++)
    {
        for ( j = 0; j < column;j++)
        {
            // Accessing all the tok
            printf("%c",token_array[i*column+j]);       
        }
        printf("\n");
    }

    // Make sure to deal for the main example
    // int main()
    // Logic work for this condition ? 
}

 
int main() 
{
    char *inputString;
    int strLength;
    char str[25] = "ex.txt";
    
    inputString = getStringFromTxtFile(str);
    if(inputString == NULL)
        return 1;

    printf("***************************************** \n");
    printf("Text as in file \n");
    printf(inputString);
    printf("\n***************************************** \n");
    strLength = strlen(inputString);
    tokenizeAndSymbolTable(inputString,strLength);

  
    return 0;
}