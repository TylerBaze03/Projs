# Kyle Dencker
# COP 2500
# 2D Lists
# October 31, 2022

def sum_row(row):
    answer = 0
    for i in range(len(row)):
        answer = answer + row[i]
    return answer;

def sum_list(matrix):
    answer = []
    for row in range(len(matrix)):
        total = 0
        for col in range(len(matrix[row])):
            total += matrix[row][col]

        answer.append(total)
    return answer

def sum_list(matrix):
    answer = []
    for row in range(len(matrix)):
        total = sum_row(matrix[row])
        answer.append(total)
    return answer

def super_score(matrix):
    answer = []
    for i in range(len(matrix)):
        highest = max(matrix[i])
        answer.append(highest)
    return sum_row(answer)

def get_average(row):
    if (len(row) == 0):
        return 0
    total = sum_row(row)
    return total / len(row)

def drop_lowest(row):
    row = row.copy()
    if (len(row) == 0):
        return row
    lowest = min(row)
    row.remove(lowest)
    return row

def drop_x_lowest(row, amount):
    row = row.copy()
    for i in range(amount):
        row = drop_lowest(row)
    return row

def drop_all_lowest(matrix, amount):
    matrix = matrix.copy()
    for row in range(len(matrix)):
        matrix[row] = drop_x_lowest(matrix[row], amount)

    return matrix

def average_all_grades(matrix):
    answer = []
    for row in range(len(matrix)):
        answer.append(get_average(matrix[row]))
    return answer

def main():
    test_list = [ [720, 680, 690, 800, 400],
                        [800, 610, 550, 790],
                        [480, 610] ]

    a = sum_row( test_list[1] )
    print(a)

    b = sum_list(test_list )
    print(b)

    c = super_score(test_list)
    print(c)

    d = get_average(test_list[2])
    print(d)

    e = drop_x_lowest( test_list[0], 3 )
    print(e)

    f = drop_all_lowest(test_list, 1)
    print(f)
    

    g = average_all_grades(test_list)
    print(g)

    h = average_all_grades( drop_all_lowest(test_list, 2))
    print(h)
    
    
    

main()
