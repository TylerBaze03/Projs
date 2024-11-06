<<<<<<< HEAD
# Tyler Bazemore
# Cop2500 0v64
#  Autopolygonator
# Oct 7, 2022
import turtle
#Part 1 of the assignment
sides = int(input("How many sides would you like?\n"))
length = int(input("How long would you like them?\n"))
angle = 360 / sides

for x in range(sides):
    turtle.forward(length)
    turtle.left(angle)
    
#part 2 my own logo design
def draw_invtriangle ():
    for x in range(3):
        turtle.right(120)
        turtle.forward(300)
def draw_triangle ():
    for x in range(3):
        turtle.left(120)
        turtle.forward(300)
#I want to make the image more cenetered as some parts were getting out of view
# on my screen when creating the image
        
turtle.penup()
turtle.goto(100,100)
turtle.pendown()
        
draw_invtriangle()

def draw_circle ():
    turtle.circle(50)
turtle.penup()
turtle.right(90)
turtle.forward(50)
turtle.left(90)
turtle.pendown()

draw_circle()
turtle.penup()
turtle.left(180)
turtle.forward(100)
turtle.right(90)
turtle.forward(50)
turtle.pendown()
draw_circle()

turtle.penup()
turtle.left(90)
turtle.forward(200)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(10)
turtle.pendown()

draw_circle()

turtle.penup()
turtle.goto(100,-180)
turtle.pendown()

draw_triangle()

turtle.penup()
turtle.goto(-50,-230)
turtle.pendown()
#had to fidget a lot to figute out how to make the top circle and bottom circle
#somewhat even 
draw_circle()

#Someewhat inspire by coheed and cambira logo with the triangles and circles intersecting



=======
# Tyler Bazemore
# Cop2500 0v64
#  Autopolygonator
# Oct 7, 2022
import turtle
#Part 1 of the assignment
sides = int(input("How many sides would you like?\n"))
length = int(input("How long would you like them?\n"))
angle = 360 / sides

for x in range(sides):
    turtle.forward(length)
    turtle.left(angle)
    
#part 2 my own logo design
def draw_invtriangle ():
    for x in range(3):
        turtle.right(120)
        turtle.forward(300)
def draw_triangle ():
    for x in range(3):
        turtle.left(120)
        turtle.forward(300)
#I want to make the image more cenetered as some parts were getting out of view
# on my screen when creating the image
        
turtle.penup()
turtle.goto(100,100)
turtle.pendown()
        
draw_invtriangle()

def draw_circle ():
    turtle.circle(50)
turtle.penup()
turtle.right(90)
turtle.forward(50)
turtle.left(90)
turtle.pendown()

draw_circle()
turtle.penup()
turtle.left(180)
turtle.forward(100)
turtle.right(90)
turtle.forward(50)
turtle.pendown()
draw_circle()

turtle.penup()
turtle.left(90)
turtle.forward(200)
turtle.left(90)
turtle.forward(50)
turtle.left(90)
turtle.forward(10)
turtle.pendown()

draw_circle()

turtle.penup()
turtle.goto(100,-180)
turtle.pendown()

draw_triangle()

turtle.penup()
turtle.goto(-50,-230)
turtle.pendown()
#had to fidget a lot to figute out how to make the top circle and bottom circle
#somewhat even 
draw_circle()

#Someewhat inspire by coheed and cambira logo with the triangles and circles intersecting



>>>>>>> b756d6d (Updating repositroy using git)
