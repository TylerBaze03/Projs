<<<<<<< HEAD
# Tyler Bazemore
# Cop2500 0v64
# Assignment 1.2
# Sep 11, 2022
import turtle
turtle.goto(-210,0)
turtle.forward(808)
turtle.penup()
turtle.goto(250,-154)
turtle.pendown()
wheel1 = 10
while (wheel1 > 0):
    turtle.forward(50)
    turtle.left(36)
    wheel1 = wheel1 - 1
    
turtle.penup()
turtle.goto(-50,-154)
turtle.pendown()

wheel2 = 10
while (wheel2 > 0):
    turtle.forward(50)
    turtle.left(36)
    wheel2 = wheel2 - 1
#Creates foundation for the truck aswell as the wheels
turtle.penup()
turtle.goto (-210,0)
turtle.pendown()
turtle.left (60)
turtle.forward (200)
turtle.left (30)
turtle.forward (100)
#This slope caults monsters from the ground into the back of the truckbed 
#where the automatic catcher will activate catching the monsters
roofcurve = 9
while (roofcurve > 0):
    turtle.forward (1)
    turtle.right (10)
    roofcurve = roofcurve - 1
turtle.forward (200)

truckslope = 6
while (truckslope > 0):
    turtle.forward (50)
    turtle.right (15)
    truckslope = truckslope - 1
#Creates ramp for small monster to sldie down into than be captured
turtle.left(90)
turtle.forward(288)
turtle.right(90)
turtle.forward(120)
turtle.right(180)
turtle.forward (200)
#Creating catcher that can fold down once monsters vaulted into truckbed
truckcatcher = 6
while (truckcatcher > 0):
    turtle.forward (35)
    turtle.left (15)
    truckcatcher = truckcatcher - 1
turtle.forward(68)
    
=======
# Tyler Bazemore
# Cop2500 0v64
# Assignment 1.2
# Sep 11, 2022
import turtle
turtle.goto(-210,0)
turtle.forward(808)
turtle.penup()
turtle.goto(250,-154)
turtle.pendown()
wheel1 = 10
while (wheel1 > 0):
    turtle.forward(50)
    turtle.left(36)
    wheel1 = wheel1 - 1
    
turtle.penup()
turtle.goto(-50,-154)
turtle.pendown()

wheel2 = 10
while (wheel2 > 0):
    turtle.forward(50)
    turtle.left(36)
    wheel2 = wheel2 - 1
#Creates foundation for the truck aswell as the wheels
turtle.penup()
turtle.goto (-210,0)
turtle.pendown()
turtle.left (60)
turtle.forward (200)
turtle.left (30)
turtle.forward (100)
#This slope caults monsters from the ground into the back of the truckbed 
#where the automatic catcher will activate catching the monsters
roofcurve = 9
while (roofcurve > 0):
    turtle.forward (1)
    turtle.right (10)
    roofcurve = roofcurve - 1
turtle.forward (200)

truckslope = 6
while (truckslope > 0):
    turtle.forward (50)
    turtle.right (15)
    truckslope = truckslope - 1
#Creates ramp for small monster to sldie down into than be captured
turtle.left(90)
turtle.forward(288)
turtle.right(90)
turtle.forward(120)
turtle.right(180)
turtle.forward (200)
#Creating catcher that can fold down once monsters vaulted into truckbed
truckcatcher = 6
while (truckcatcher > 0):
    turtle.forward (35)
    turtle.left (15)
    truckcatcher = truckcatcher - 1
turtle.forward(68)
    
>>>>>>> b756d6d (Updating repositroy using git)
