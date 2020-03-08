# 6.00.2x Problem Set 2: Simulating robots

import math
import random

import ps2_visualize
import pylab

##################
## Comment/uncomment the relevant lines, depending on which version of Python you have
##################

# For Python 3.5:
#from ps2_verify_movement35 import testRobotMovement
# If you get a "Bad magic number" ImportError, you are not using Python 3.5 

# For Python 3.6:
#from ps2_verify_movement36 import testRobotMovement
# If you get a "Bad magic number" ImportError, you are not using Python 3.6

from ps2_verify_movement37 import testRobotMovement
# === Provided class Position
class Position(object):
    """
    A Position represents a location in a two-dimensional room.
    """
    def __init__(self, x, y):
        """
        Initializes a position with coordinates (x, y).
        """
        self.x = x
        self.y = y
        
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
    def getNewPosition(self, angle, speed):
        """
        Computes and returns the new Position after a single clock-tick has
        passed, with this object as the current position, and with the
        specified angle and speed.

        Does NOT test whether the returned position fits inside the room.

        angle: number representing angle in degrees, 0 <= angle < 360
        speed: positive float representing speed

        Returns: a Position object representing the new position.
        """
        old_x, old_y = self.getX(), self.getY()
        angle = float(angle)
        # Compute the change in position
        delta_y = speed * math.cos(math.radians(angle))
        delta_x = speed * math.sin(math.radians(angle))
        # Add that to the existing position
        new_x = old_x + delta_x
        new_y = old_y + delta_y
        return Position(new_x, new_y)

    def __str__(self):  
        return "(%0.2f, %0.2f)" % (self.x, self.y)


# === Problem 1
class RectangularRoom(object):
    """
    A RectangularRoom represents a rectangular region containing clean or dirty
    tiles.

    A room has a width and a height and contains (width * height) tiles. At any
    particular time, each of these tiles is either clean or dirty.
    """
    def __init__(self, width, height):
        """
        Initializes a rectangular room with the specified width and height.

        Initially, no tiles in the room have been cleaned.

        width: an integer > 0
        height: an integer > 0
        """
        self.width = width
        self.height = height
        #self.isCleaned = [[0 for x in range(width)] for y in range(height)]
        self.isCleaned = [[0 for x in range(height)] for y in range(width)]
    
    def cleanTileAtPosition(self, pos):
        """
        Mark the tile under the position POS as cleaned.

        Assumes that POS represents a valid position inside this room.

        pos: a Position
        """
        self.isCleaned[int(pos.getX())][int(pos.getY())] = True
        

    def isTileCleaned(self, m, n):
        """
        Return True if the tile (m, n) has been cleaned.

        Assumes that (m, n) represents a valid tile inside the room.

        m: an integer
        n: an integer
        returns: True if (m, n) is cleaned, False otherwise
        """
        # n is the column number
        # m is the row number
        if self.isCleaned[m][n]:
            return True
        else:
            return False
    
    def getNumTiles(self):
        """
        Return the total number of tiles in the room.

        returns: an integer
        """
        return self.width*self.height
    

    def getNumCleanedTiles(self):
        """
        Return the total number of clean tiles in the room.

        returns: an integer
        """
        count = 0
        #print(self.width, self.height)
        for x in range(self.width):
            for y in range(self.height):
                #print(x,y)
                if self.isCleaned[x][y]:
                    count += 1
        return count

    def getRandomPosition(self):
        """
        Return a random position inside the room.

        returns: a Position object.
        """
        return Position(random.randint(0,self.width-1),random.randint(0,self.height-1))

    def isPositionInRoom(self, pos):
        """
        Return True if pos is inside the room.

        pos: a Position object.
        returns: True if pos is in the room, False otherwise.
        """
        return (
                (pos.getX() < self.width and pos.getX() >=0 ) 
                and (pos.getY() < self.height and pos.getY() >= 0)
                )


# === Problem 2
class Robot(object):
    """
    Represents a robot cleaning a particular room.

    At all times the robot has a particular position and direction in the room.
    The robot also has a fixed speed.

    Subclasses of Robot should provide movement strategies by implementing
    updatePositionAndClean(), which simulates a single time-step.
    """
    def __init__(self, room, speed):
        """
        Initializes a Robot with the given speed in the specified room. The
        robot initially has a random direction and a random position in the
        room. The robot cleans the tile it is on.

        room:  a RectangularRoom object.
        speed: a float (speed > 0)
        """
        self.room = room
        self.speed = speed
        self.direction = random.randint(0,360)
        self.pos = self.room.getRandomPosition()

    def getRobotPosition(self):
        """
        Return the position of the robot.

        returns: a Position object giving the robot's position.
        """
        return self.pos
        
    
    def getRobotDirection(self):
        """
        Return the direction of the robot.

        returns: an integer d giving the direction of the robot as an angle in
        degrees, 0 <= d < 360.
        """
        return self.direction;

    def setRobotPosition(self, position):
        """
        Set the position of the robot to POSITION.

        position: a Position object.
        """
        self.pos = position

    def setRobotDirection(self, direction):
        """
        Set the direction of the robot to DIRECTION.

        direction: integer representing an angle in degrees
        """
        self.direction = direction

    def updatePositionAndClean(self):
        """
        Simulate the passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        raise NotImplementedError # don't change this!


# === Problem 3
class StandardRobot(Robot):
    """
    A StandardRobot is a Robot with the standard movement strategy.

    At each time-step, a StandardRobot attempts to move in its current
    direction; when it would hit a wall, it *instead* chooses a new direction
    randomly.
    """
    def updatePositionAndClean(self):
        """
        Simulate the passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        
        #clean current location first
        #print("clean :" + str(int(self.pos.getX())) + " " + str(int(self.pos.getY())))
        self.room.cleanTileAtPosition(self.pos)
        
        #get the robot's next position using current dictrion
        newPos = self.pos.getNewPosition(self.direction,self.speed)
        #if next position is not in the room
        while(not self.room.isPositionInRoom(newPos)):
            #then get a new direction and set it to current direction
            newdir = random.randint(0,360)
            self.setRobotDirection(newdir)
            #get next position based on the new direction
            newPos = self.pos.getNewPosition(self.direction,self.speed)
        #set next position
        self.setRobotPosition(newPos)


# Uncomment this line to see your implementation of StandardRobot in action!
#testRobotMovement(StandardRobot, RectangularRoom)


# === Problem 4
def runSimulation(num_robots, speed, width, height, min_coverage, num_trials,
                  robot_type):
    """
    Runs NUM_TRIALS trials of the simulation and returns the mean number of
    time-steps needed to clean the fraction MIN_COVERAGE of the room.

    The simulation is run with NUM_ROBOTS robots of type ROBOT_TYPE, each with
    speed SPEED, in a room of dimensions WIDTH x HEIGHT.

    num_robots: an int (num_robots > 0)
    speed: a float (speed > 0)
    width: an int (width > 0)
    height: an int (height > 0)
    min_coverage: a float (0 <= min_coverage <= 1.0)
    num_trials: an int (num_trials > 0)
    robot_type: class of robot to be instantiated (e.g. StandardRobot or
                RandomWalkRobot)
    """
    step_sum = 0
    for t in range(num_trials):
        #anim = ps2_visualize.RobotVisualization(num_robots, width, height) #simulation
        mean_steps = [0 for x in range(num_trials)]
        room = RectangularRoom(width,height)
        robots = list()
        for r in range(num_robots):
            robots.append(robot_type(room,speed))
        while(room.getNumCleanedTiles() < room.getNumTiles() * min_coverage):
            #anim.update(room, robots) #simulation
            for r in range(num_robots):
                robots[r].updatePositionAndClean()
            mean_steps[t] += 1
        step_sum += mean_steps[t]
        #anim.done() #simulation
    return int(step_sum/num_trials)
        

# Uncomment this line to see how much your simulation takes on average
#print(runSimulation(1, 1.0, 10, 10, 0.75, 30, StandardRobot))
#print(runSimulation(1, 1.0, 5, 5, 1, 300, StandardRobot))
#print(runSimulation(1, 1.0, 10, 10, 0.9, 30, StandardRobot))
#print(runSimulation(1, 1.0, 20, 20, 1, 30, StandardRobot))
#print(runSimulation(3, 1.0, 20, 20, 1, 30, StandardRobot))
#print(runSimulation(10, 1.0, 20, 20, 1, 30, StandardRobot))
#print(runSimulation(100, 1.0, 100, 100, 1, 30, StandardRobot))

# === Problem 5
class RandomWalkRobot(Robot):
    """
    A RandomWalkRobot is a robot with the "random walk" movement strategy: it
    chooses a new direction at random at the end of each time-step.
    """
    def updatePositionAndClean(self):
        """
        Simulate the passage of a single time-step.

        Move the robot to a new position and mark the tile it is on as having
        been cleaned.
        """
        #clean current location first
        #print("clean :" + str(int(self.pos.getX())) + " " + str(int(self.pos.getY())))
        self.room.cleanTileAtPosition(self.pos)        
        #get the robot's next position using current dictrion
        newdir = random.randint(0,360)
        newPos = self.pos.getNewPosition(newdir,self.speed)
        #if next position is not in the room
        while(not self.room.isPositionInRoom(newPos)):
            #then get a new direction and set it to current direction
            newdir = random.randint(0,360)
            #get next position based on the new direction
            newPos = self.pos.getNewPosition(newdir,self.speed)
        #set next direciton and position
        self.setRobotDirection(newdir)
        self.setRobotPosition(newPos) 
#print(runSimulation(3, 1.0, 10, 10, 1 , 30, RandomWalkRobot))

def showPlot1(title, x_label, y_label):
    """
    What information does the plot produced by this function tell you?
    """
    num_robot_range = range(1, 11)
    times1 = []
    times2 = []
    for num_robots in num_robot_range:
        print("Plotting", num_robots, "robots...")
        times1.append(runSimulation(num_robots, 1.0, 20, 20, 0.8, 20, StandardRobot))
        times2.append(runSimulation(num_robots, 1.0, 20, 20, 0.8, 20, RandomWalkRobot))
    pylab.plot(num_robot_range, times1)
    pylab.plot(num_robot_range, times2)
    pylab.title(title)
    pylab.legend(('StandardRobot', 'RandomWalkRobot'))
    pylab.xlabel(x_label)
    pylab.ylabel(y_label)
    pylab.show()

    
def showPlot2(title, x_label, y_label):
    """
    What information does the plot produced by this function tell you?
    """
    aspect_ratios = []
    times1 = []
    times2 = []
    for width in [10, 20, 25, 50]:
        height = 300//width
        print("Plotting cleaning time for a room of width:", width, "by height:", height)
        aspect_ratios.append(float(width) / height)
        times1.append(runSimulation(2, 1.0, width, height, 0.8, 200, StandardRobot))
        times2.append(runSimulation(2, 1.0, width, height, 0.8, 200, RandomWalkRobot))
    pylab.plot(aspect_ratios, times1)
    pylab.plot(aspect_ratios, times2)
    pylab.title(title)
    pylab.legend(('StandardRobot', 'RandomWalkRobot'))
    pylab.xlabel(x_label)
    pylab.ylabel(y_label)
    pylab.show()
    

# === Problem 6
# NOTE: If you are running the simulation, you will have to close it 
# before the plot will show up.

#
# 1) Write a function call to showPlot1 that generates an appropriately-labeled
#     plot.
#
#       (... your call here ...)
    
showPlot1("Time It Takes 1 - 10 Robots To Clean 80% Of A Room","Number of Robots","Time-steps")
    
#

#
# 2) Write a function call to showPlot2 that generates an appropriately-labeled
#     plot.
#
#       (... your call here ...)
#
showPlot2("Time It Takes Two Robots To Clean 80% Of Variously Shaped Rooms","Aspect Ratio","Time-steps")

###############################
#problem 1 unit test
###############################
#room = RectangularRoom(10,10)
#print(room.getNumTiles())
#
#pos1 = Position(-1,-1)
#pos2 = Position(1,11)
#print(room.isPositionInRoom(pos1))
#print(room.isPositionInRoom(pos2))
#
#pos0 = Position(0,0)
#pos3 = Position(5,6)
##pos4 = Position(5,5)
#room.cleanTileAtPosition(pos0)
#room.cleanTileAtPosition(pos3)
#print(room.getNumCleanedTiles())
#print(room.isTileCleaned(0,0))
#print(room.isTileCleaned(5,6))
#print(room.isTileCleaned(5,5))
#print(room.isTileCleaned(6,5))
###############################
#problem 1 unit test done
###############################