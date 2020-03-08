# -*- coding: utf-8 -*-
"""
Created on Sat Jan 26 15:05:37 2019

@author: yuhan
"""
#yuhang note:
#the idea is to use the each bit in an iterger to indicate whether it's in or not
#0 for not in, and 1 for in.
#for example
#if N=3, two items
#then we have 8 different combinations
#000 (0), none of the items is in
#001 (1), 1st item in
#010 (2), 2nd item in
#011 (3), 1st and 2nd item in
#100 (4), 3rd item in
#101 (5), 1st and 3rd items in
#110 (6), 2nd and 3rd items in
#111 (7), all items in
#if the item is in, then append to the combo(a list of items)

#sample code of 2^N power set
## generate all combinations of N items
#def powerSet(items):
#    N = len(items)
#    # enumerate the 2**N possible combinations
#    for i in range(2**N):
#        combo = []
#        for j in range(N):
#            # test bit jth of integer i
#            if (i >> j) % 2 == 1:
#                combo.append(items[j])
#        yield combo
#yuhang note end


#As above, suppose we have a generator that returns every combination of 
#objects in one bag. We can represent this as a list of 1s and 0s denoting 
#whether each item is in the bag or not.
#
#Write a generator that returns every arrangement of items such that 
#each is in one or none of two different bags. Each combination 
#should be given as a tuple of two lists, the first being the items in bag1, 
#and the second being the items in bag2.
#

def yieldAllCombos(items):
#    """
#      Generates all combinations of N items into two bags, whereby each 
#      item is in one or zero bags.
#
#      Yields a tuple, (bag1, bag2), where each bag is represented as 
#      a list of which item(s) are in each bag.
#    """
# Your code here
    N = len(items)
    #enumerate the 3^N possible combinations
    for i in range(3^N):
        combo = ([],[])
        for j in range(N):
            #if((i>>j) % 3 == 1):
            if (i // (3 ** j)) % 3 == 1:
                combo[0].append(items[j])
            #elif ((i>>j) % 3 == 2):
            if (i // (3 ** j)) % 3 == 2:
                combo[1].append(items[j])
            yield combo