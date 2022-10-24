"""
     Anirudh Sathish 
     CS20B1125 
     Lab5 : DS
"""


list_word_t =[]
with open("ex.txt") as file:
    for item in file:
        item = item.replace('\n',"")
        list_word_t.append(item)
new = []
for word in list_word_t:
    sub_str = " "
    if sub_str in word:
        word = word.split(" ")
        for w in word:
            if w != '':
                new.append(w)
    else:
        new.append(word)

list_word_t =[]
msgstr = ""
with open("ex.txt") as file:
    for item in file:
        item = item.replace('\n'," ")
        msgstr = msgstr+item

#Store all neccesary information 

header_files =["#include<stdio.h>","#include<stdlib.h>","#include<string.h>"]
keywords = ["auto","break","case","char" ,"const",
                            "continue","default","do","else"
                            "enum","extern" ,"for","goto","if",
                            "long","register","return",
                            "short"	,"signed","sizeof","static",
                            "struct","switch","typedef","union",
                            "unsigned","void","volatile","while", "main()"]
operators = ['+','-','*','/','%','^',"&&","||"]
otherSymb = [',',';','{',"}"]
data_types = ["int","float","double","char","long"]


li = []
msgs = msgstr.split(" ")
for m in msgs:
    if m != '' and m!=' ':
        li.append(m)
dictSymbolTable ={}
dictSymbolCountTable = {}


lis_len = len(li)
word_count = 0
keysInDict = [] 


#Deal with reassignment and single line assignment 
for i in range(lis_len):

    if li[i] in data_types:
        #It has read a data_type
        #Now check what it reads in the next word
        next_word = li[i+1]
        #Check if next word is a keyword or operator
        if next_word not in keywords:
            curr = li[i]
            list2 = []
            list2.append(curr)
            dictSymbolTable[next_word] = list2
            keysInDict.append(next_word)

            #Looping till u find a ;
            i=i+1
            while(next_word != ';'):
                word_count = word_count+1
                next_word= li[i+1]
                if next_word not in keywords:
                    if next_word not in otherSymb:
                        list2 = []
                        list2.append(curr)
                        dictSymbolTable[next_word] = list2
                        keysInDict.append(next_word)
                i=i+1


    if li[i] in keysInDict:
        var = li[i]
        next = li[i+1]
        if(next == '='):
            i=i+1
            nextval = li[i+1]
            l = dictSymbolTable[var]
            l.append(nextval)
            dictSymbolTable[var]=l

print(dictSymbolTable)
print("Displaying the symbolTable")
print("\n")
print("---------------------------------------------------------")
for dict in dictSymbolTable:
    print("The token is : ",dict)
    len_2 = len(dictSymbolTable[dict])
    if(len_2 == 2):
        print("The attribute 1 is : ",dictSymbolTable[dict][0])
        print("The attribute 2 is : ",dictSymbolTable[dict][1])
    else:
        print("The attribute 1 is : ",dictSymbolTable[dict][0])
    print("\n")
    print("---------------------------------------------------------")


