#SET Up an advising appointment

schedule = ["1:00","1:30","2:00","2:30","TAKEN","3:30","4:00"]
end = "All done"
appointment = ""
def scheduletimes():
    for number, letter in enumerate(schedule):
            print(number+1,".", letter, sep = "")
            
print("Wellcome to your advising appointment scheduler\n To set an appointment please say the time such as 1:00")
print("When you are satisfied with your appointment, or done, please type All done")

while appointment != end:
    scheduletimes()
    appointment  = str(input("Please select a time\n"))
#Have to do a for statement to make sure it checks if its even in
#the lsit to start off lmao
    for x in range(len(schedule)):
        if schedule.index(appointment) != schedule.index("TAKEN"):
            app_num = schedule.index(appointment)
            schedule[app_num] = "TAKEN"
        else:
            print("broke")
        
