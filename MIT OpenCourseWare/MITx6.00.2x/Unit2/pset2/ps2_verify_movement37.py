def testRobotMovement(robot_type, room_type, delay=0.4):
    """
    Runs a simulation of a single robot of type robot_type in a 5x5 room.
    """
    import ps2_visualize
    #room = room_type(5, 5)
    room = room_type(10, 10)
    robot = robot_type(room, 1)
    #anim = ps2_visualize.RobotVisualization(1, 5, 5, delay)
    anim = ps2_visualize.RobotVisualization(1, 10, 10, delay)
    while room.getNumCleanedTiles() < room.getNumTiles():
        ## move the robot ##
        robot.updatePositionAndClean()
        anim.update(room, [robot])
    anim.done()