# Tyler Bazemore
# Cop2500 0v64
# Assignment 2.1
# Sep 14, 2022
people = int(input("How many people are going to see the movie?\n"))
smc = str(input("Are you a Small Monster Collector?\n Yes or No\n"))
smctix = 9.50
stndrdtix = 12
lrggrptix = 7.25
#Set up variable for equations later
if smc == "Yes":
    if people >= 25:
        print("The total ticket price is ",people*lrggrptix)
    else:
        print("The total ticket price is ",((people-1)*stndrdtix)+smctix)
else:
    if people >= 25:
        print("The total ticket price is ",people*lrggrptix)
    else:
        print("The total ticket price is ",people*stndrdtix)
