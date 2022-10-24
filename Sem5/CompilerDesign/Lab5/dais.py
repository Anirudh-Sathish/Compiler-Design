# -*- coding: utf-8 -*-
"""
Created on Wed Aug 24 21:46:16 2022

@author: aniru
"""

list_word_t =[]
with open("ex.txt") as file:
    for item in file:
        item = item.replace('\n',"")
        list_word_t.append(item)