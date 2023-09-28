# Tyler Bazemore
# Cop2500 0v64
# Lab 3 Challenge 3
# Sep 19, 2022
travelagent = 1
place = str(input("Where would you like to go?\n"))
if place == "Theme Park":
    days = int(input("How many days are you going for?\n"))
    while (days > 0):
        print("Day", travelagent, "Park", travelagent)
        days -= 1
        travelagent += 1
elif place == ("Science Center"):
#Figured a function would work best to make a loop until the ready command was input    
    def main():
        ready = str(input("Are you ready to go?\n"))
        if ready == "Ready":
            print("Lets go!")
        else:
            main()
    main()
            
    
    
