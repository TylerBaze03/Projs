<<<<<<< HEAD
# Tyler Bazemore
# Cop2500 0v64
# Lab 2 Challenge 3
# Sep 7, 2022
place = str(input("Where would you like to go?\nBeach or Theme Park? "))
if place == "Beach":
    beachballs = int(input("How many beach balls do you have? "))
    if beachballs >= 5:
        print("You are well prepared")
    elif beachballs >= 0:
        print("Are you sure you have enough?")
    else:
        print("That is not possible")
if place == "Theme Park":
    people = int(input("How many people are going to be at the park?"))
    if people > 1000:
        print("This is toooo crowded")
    elif people >= 500:
        print("It's going to be busy")
    elif people >= 100:
        print("it's a light day")
    elif people >= 0:
        print("Theres nobody here...")
            
=======
# Tyler Bazemore
# Cop2500 0v64
# Lab 2 Challenge 3
# Sep 7, 2022
place = str(input("Where would you like to go?\nBeach or Theme Park? "))
if place == "Beach":
    beachballs = int(input("How many beach balls do you have? "))
    if beachballs >= 5:
        print("You are well prepared")
    elif beachballs >= 0:
        print("Are you sure you have enough?")
    else:
        print("That is not possible")
if place == "Theme Park":
    people = int(input("How many people are going to be at the park?"))
    if people > 1000:
        print("This is toooo crowded")
    elif people >= 500:
        print("It's going to be busy")
    elif people >= 100:
        print("it's a light day")
    elif people >= 0:
        print("Theres nobody here...")
            
>>>>>>> b756d6d (Updating repositroy using git)
