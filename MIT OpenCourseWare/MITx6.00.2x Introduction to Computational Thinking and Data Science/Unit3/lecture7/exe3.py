# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 20:28:32 2019

@author: yuhan
"""

import math

def stdDevOfLengths(L):
    string_lens = []
    if (len(L)==0):
        return float('NaN')
    num_strings = len(L)
    for s in L:
        string_lens.append(len(s))
    len_sum = 0
    for length in string_lens:
        len_sum += length
    u = len_sum / num_strings
    
    sum_of_quantity = 0
    for length in string_lens:
        sum_of_quantity += (length-u)*(length-u)
    
    return math.sqrt(sum_of_quantity / num_strings)

L1 = ['a','z','p']
L2 = ['apples', 'oranges', 'kiwis', 'pineapples']

print(stdDevOfLengths(L1))
print(stdDevOfLengths(L2))