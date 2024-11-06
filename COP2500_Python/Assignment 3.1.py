<<<<<<< HEAD
# Tyler Bazemore
# Assignment 3.1
# COP2500 ov64
end = "EXIT"
classes = []
new_class = ""
def classlist():
    for number, letter in enumerate(classes):
            print(number+1,".", letter, sep = "")
print("Wellcome to class registration!")
while new_class != end:
    new_class = str(input("Enter a course code:\n"))
    if new_class == end:
            print("Goodbye")
    else:
        classes.append(new_class)
        classlist()
        if len(classes) > 5:
            del_num = int(input("Which class would you want to delete, 1-6"))
            while del_num  < 1 or del_num > 6:
                del_num = int(input("Invalid input, which class would you want to delete, 1-6\n"))
            del_num = del_num - 1
            classes.pop(del_num)
            classlist()
      


# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
end = "EXIT"
classes = []
new_class = ""
def classlist():
    for num, item in enumerate(*classes):
            print(num+1,":", item)
print("You aren't taking any courses.\n")
while len(classes) != 5:
    if len(classes) < 5:
        new_class = str(input("Enter courses:\n"))
        new_class = new_class.title()
        new_class = new_class.strip()
        new_classlist = new_class.split(", ")
        classes.append(new_classlist)
        classlist()
    elif len(classes) > 5:
        del_class = str(input("Which class would you want to drop?"))
        classes.pop(del_class)
        classlist()
       
       
       
=======
# Tyler Bazemore
# Assignment 3.1
# COP2500 ov64
end = "EXIT"
classes = []
new_class = ""
def classlist():
    for number, letter in enumerate(classes):
            print(number+1,".", letter, sep = "")
print("Wellcome to class registration!")
while new_class != end:
    new_class = str(input("Enter a course code:\n"))
    if new_class == end:
            print("Goodbye")
    else:
        classes.append(new_class)
        classlist()
        if len(classes) > 5:
            del_num = int(input("Which class would you want to delete, 1-6"))
            while del_num  < 1 or del_num > 6:
                del_num = int(input("Invalid input, which class would you want to delete, 1-6\n"))
            del_num = del_num - 1
            classes.pop(del_num)
            classlist()
      


# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
end = "EXIT"
classes = []
new_class = ""
def classlist():
    for num, item in enumerate(*classes):
            print(num+1,":", item)
print("You aren't taking any courses.\n")
while len(classes) != 5:
    if len(classes) < 5:
        new_class = str(input("Enter courses:\n"))
        new_class = new_class.title()
        new_class = new_class.strip()
        new_classlist = new_class.split(", ")
        classes.append(new_classlist)
        classlist()
    elif len(classes) > 5:
        del_class = str(input("Which class would you want to drop?"))
        classes.pop(del_class)
        classlist()
       
       
       
>>>>>>> b756d6d (Updating repositroy using git)
range(len(del_class)-1)