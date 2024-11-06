<<<<<<< HEAD
# Tyler Bazemore
# Assignment 5.1
# COP2500 ov64

import math
import turtle
import random
def randomTurtle():
    for count in range(10):
        choice = random.randint(1,2)
        if (choice == 1):
            turtle.forward(random.randint(5, 50))
        elif(choice == 2):
            turtle.right(random.randint(1,359))
def testTurtle():
    turtle.forward(100)
    turtle.left(90)
    turtle.forward(100)

def distance(x, y):
    print(math.sqrt((x**2)+(y**2)))
randomTurtle()

#testTurtle()
distance(turtle.xcor(), turtle.ycor())
=======
# Tyler Bazemore
# Assignment 5.1
# COP2500 ov64

import math
import turtle
import random
def randomTurtle():
    for count in range(10):
        choice = random.randint(1,2)
        if (choice == 1):
            turtle.forward(random.randint(5, 50))
        elif(choice == 2):
            turtle.right(random.randint(1,359))
def testTurtle():
    turtle.forward(100)
    turtle.left(90)
    turtle.forward(100)

def distance(x, y):
    print(math.sqrt((x**2)+(y**2)))
randomTurtle()

#testTurtle()
distance(turtle.xcor(), turtle.ycor())
>>>>>>> b756d6d (Updating repositroy using git)
