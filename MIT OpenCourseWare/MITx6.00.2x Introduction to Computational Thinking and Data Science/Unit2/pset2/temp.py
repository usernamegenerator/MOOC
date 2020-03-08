# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 18:12:36 2019

@author: yuhan
"""

def testRobotMovement(robot_type, room_type, delay=0.4):
    """
    Runs a simulation of a single robot of type robot_type in a 5x5 room.
    """
    import ps2_visualize
    room = room_type(5, 5)
    robot = robot_type(room, 1)
    anim = ps2_visualize.RobotVisualization(1, 5, 5, delay)
    while ## the room is not cleaned ##
        ## move the robot ##
        anim.update(room, [robot])
    anim.done()