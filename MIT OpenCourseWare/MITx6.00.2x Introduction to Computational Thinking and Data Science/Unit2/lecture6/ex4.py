# -*- coding: utf-8 -*-
"""
Created on Tue Feb 12 23:17:51 2019

@author: yuhan
"""
#
#import random
#def takeStep():
#    # code for takeStep()
#    directionList = [(0.0, 1.0), (1.0, 0.0), (-1.0, 0.0), (0.0, -1.0)]
#    myDirection = random.choice(directionList)
#    print (myDirection)
#    if myDirection[0] == 0.0:
#        print (myDirection)
#        return myDirection + (0.0, -0.5)
#    return myDirection
#
#print(takeStep())



Exercise 4
1 point possible (graded)
Suppose we wanted to create a class PolarBearDrunk, a drunk polar bear who moves randomly along the x and y axes taking large steps when moving South, and small steps when moving North.

class PolarBearDrunk(Drunk):
    def takeStep(self):
        # code for takeStep()
Which of the following would be an appropriate implementation of takeStep()?

Option A)

directionList = [(0.0, 1.0), (1.0, 0.0), (-1.0, 0.0), (0.0, -1.0)]
myDirection = random.choice(directionList)
if myDirection[0] == 0.0:
    return myDirection + (0.0, -0.5)
return myDirection
Option B)

directionList = [(0.0, 0.5), (1.0, -0.5), (-1.0, -0.5), (0.0, -1.5)]
return random.choice(directionList)
Option C)

directionList = [(0.0, 0.5), (1.0, 0.0), (-1.0, 0.0), (0.0, -1.5)]
return random.choice(directionList)
Option D)

directionList = [(0.0, 1.0), (1.0, 0.0), (-1.0, 0.0), (0.0, -1.0), (0.0, -1.0)]
return random.choice(directionList)

Option A)
Option B)
Option C) correct
Option D)
unanswered
Explanation:

Option A) is incorrect because it produces tuples of length 4. The logic is otherwise correct, but it should be written as:

directionList = [(0.0, 1.0), (1.0, 0.0), (-1.0, 0.0), (0.0, -1.0)]
myDirection = random.choice(directionList)
if myDirection[0] == 0.0:
    return (myDirection[0], myDirection[1] - 0.5) 
return myDirection
Option B) is incorrect because it produces directions not along axes.

Option D) is incorrect because it produces a bias toward moving South, but does not alter step size.