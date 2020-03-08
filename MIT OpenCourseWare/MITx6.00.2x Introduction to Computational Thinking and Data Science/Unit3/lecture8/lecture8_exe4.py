# -*- coding: utf-8 -*-
"""
Exercise 4
0.0/5.0 points (graded)
You have a bucket with 3 red balls and 3 green balls. 
Assume that once you draw a ball out of the bucket, you don't replace it. 
What is the probability of drawing 3 balls of the same color?

Write a Monte Carlo simulation to solve the above problem. 
Feel free to write a helper function if you wish.
"""

import random
def noReplacementSimulation(numTrials):
    '''
    Runs numTrials trials of a Monte Carlo simulation
    of drawing 3 balls out of a bucket containing
    3 red and 3 green balls. Balls are not replaced once
    drawn. Returns the a decimal - the fraction of times 3 
    balls of the same color were drawn.
    '''
    # Your code here
    numOfDraws = 3
    cntOfSameColor = 0
    for trial in range(numTrials):
        #1 for red and 0 for green
        bagOfBalls = [1,1,1,0,0,0]
        chosenBalls = []
        for draw in range(numOfDraws):
            ball = random.choice(bagOfBalls)
            bagOfBalls.remove(ball)
            chosenBalls.append(ball)
        if(chosenBalls[0] == chosenBalls[1] and chosenBalls[0] == chosenBalls[2]):
            cntOfSameColor += 1
    return (float)(cntOfSameColor) / (float)(numTrials)
            
print(noReplacementSimulation(3000))