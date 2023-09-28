# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
classes = []
new_class = ""
def classlist():
    for num, letter in enumerate(classes):
            print(num+1,":", letter, sep = "")
print("You aren't taking any courses.\n")
while len(classes) != 5:
    if len(classes) < 5:
        new_class = str(input("Enter courses:\n"))
        new_class = new_class.title()
        new_class = new_class.strip().replace(" ", "")
        new_class = new_class.split(",")
        classes.extend(new_class)
        classlist()
    elif len(classes) > 5:
        del_class = str(input("Which class would you want to drop?\n"))
        del_class = del_class.title()
        del_class = del_class.strip().replace(" ", "")
        del_class = del_class.split(",")
        for i in del_class:
            if i not in classes:
                del_class.pop[i]
            else:
                classes.remove(i)
        classlist()
print("All done")
