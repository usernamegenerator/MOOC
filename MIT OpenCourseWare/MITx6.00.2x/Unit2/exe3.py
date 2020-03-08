# -*- coding: utf-8 -*-
"""
Created on Sat Feb  2 15:57:37 2019

@author: yuhan
"""

#Exercise 3-1
#0.0/5.0 points (graded)
#Write a deterministic program, deterministicNumber, that returns an even number between 9 and 21.

import random
def deterministicNumber():
    '''
    Deterministically generates and returns an even number between 9 and 21
    '''
    #return random.choice(range(10, 22,2))
    return 10

print (deterministicNumber())

#Write a uniformly distributed stochastic program, stochasticNumber, that returns an even number between 9 and 21.

def stochasticNumber():
    '''
    Stochastically generates and returns a uniformly distributed even number between 9 and 21
    '''
    # Your code here
    return random.choice(range(10,22,2))

print (stochasticNumber())