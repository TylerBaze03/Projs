# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
endresult = []
semester = [[95,92,93,96,92],
            [100,100],
            [70,80,90],
            [95,85,75,70]]
def gradechanges(grades):
    for i in range(len(grades)):
        diff = 0
        for x in range(1, len(grades[i])):
            if (grades[i])[x - 1] < (grades[i])[x]:
                diff = diff + 1
            else:
                pass
        endresult.append(diff)
    return endresult
                



print(gradechanges(semester))
