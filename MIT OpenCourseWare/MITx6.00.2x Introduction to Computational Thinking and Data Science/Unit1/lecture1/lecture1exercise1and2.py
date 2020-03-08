# -*- coding: utf-8 -*-
"""
Created on Wed Jan 23 22:25:10 2019
As a burgler robs a house, she finds the following items:

Dirt - Weight: 4, Value: 0
Computer - Weight: 10, Value: 30
Fork - Weight: 5, Value: 1
Problem Set - Weight: 0, Value: -10
This time, she can only carry a weight of 14, and wishes to maximize the value to weight ratio of the things she carries. She employs three different metrics in an attempt to do this, and writes an algorithm in Python to determine which loot to take.

The algorithm works as follows:

Evaluate the metric of each item. Each metric returns a numerical value for each item.
For each item, from highest metric value to lowest, add the item if there is room in the bag.
"""

class item:
    def __init__(self):
        self.value = 0
        self.weight = 0
    def __init__(self,v,w,n):
        self.value = v
        self.weight = w
        self.name = n
    def getValue(self):
        return self.value;
    def getWeight(self):
        return self.weight;
    def metric1(self):
        if (self.getWeight() == 0):
            return self.getValue() / 0.000001
        return self.getValue() / self.getWeight()
    def metric2(self):
        return -self.getWeight()
    def metric3(self):
        return self.getValue()
    def getName(self):
        return self.name
    def __repr__(self):
        return repr((self.value,self.weight,self.name,self.metric1(),
                     self.metric2(),self.metric3()))

    

def algorithm(itemList,weightTotal):
    
    itemList.sort(key = lambda item: item.metric1(),reverse=True)
    #print(itemList)
    weightTaken = 0
    bag = []
    i=0
    while(i<len(itemList)):
        if(weightTaken + itemList[i].getWeight() <= weightTotal):
            bag.append(itemList[i])
            weightTaken += itemList[i].getWeight()
        i = i+1
        
    print ("metric1 max value/weight ratio picks: ")
    print (bag)
    #print ("ex1 metric1 Choose the item with the best value to weight ratio first.")
    #print ("ex1 metric1 doesn't run because it's divided by 0")
    
    print("====================================================")
    
    itemList.sort(key = lambda item: item.metric2(),reverse=True)
    #print(itemList)
    weightTaken = 0
    bag = []
    i=0
    while(i<len(itemList)):
        if(weightTaken + itemList[i].getWeight() <= weightTotal):
            bag.append(itemList[i])
            weightTaken += itemList[i].getWeight()
        i = i+1
    print ("metric2 min weight picks: ")
    print (bag)
    #print ("ex1 metric2 Choose the lightest object first.")
    #print ("ex1 metric2 is NOT the optimal solution")
    
    
    print("====================================================")
    
    itemList.sort(key = lambda item: item.metric3(),reverse=True)
    #print(itemList)
    weightTaken = 0
    bag = []
    i=0
    while(i<len(itemList)):
        if(weightTaken + itemList[i].getWeight() <= weightTotal):
            bag.append(itemList[i])
            weightTaken += itemList[i].getWeight()
        i = i+1
    print ("metric3 max value picks: ")
    print (bag)
    #print ("ex1 metric3 Choose the most valuable object first. ")
    #print ("ex1 metric3 is the NOT optimal solution")
        
    print("====================================================")
    
        


def main():
    #print ("main")
    print("exercise 1")
    weightTotal = 14
    Dirt = item(0,4,"Dirt")
    Computer = item(30,10,"Computer")
    Fork = item(1,5,"Fork")
    Problem = item(-10,0,"Problem")
    itemListEx1 = [Dirt,Computer,Fork,Problem]
    algorithm(itemListEx1,weightTotal)
    print("***********************************************************")
    print("exercise 2")
    weightTotal = 20
    clock = item(174,10,"clock")
    picture = item(90,9,"picture")
    radio = item(20,4,"radio")
    vase = item(50,2,"vase")
    book = item(10,1,"book")
    computer = item(200,20,"computer")
    itemListEx2 = [clock,picture,radio,vase,book,computer]
    algorithm(itemListEx2,weightTotal)
    
    
if __name__ == "__main__":
    main()