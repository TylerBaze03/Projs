import random
import time
# # == to scissors, @ == unplaceable, ! == to present, X == placeable, * == faux
#['X','X','X','X','X','X'],
#['X','X','@','X','X','X'],
#['X','X','X','X','@','X'],
#['X','X','X','X','X','@'],
#['X','@','X','X','X','X'],
#['X','X','X','@','X','X']

#['X','X','@','X','X','X']
#['X','X','X','X','@','X'],
#['X','X','X','X','X','X'],
#['X','X','X','X','X','X'],
#['X','X','X','X','@','X'],
#['X','@','X','X','X','X']
# flood filling too much of the board, present needs to be implemented to the main function

board1 = [['X','X','X','X','X','X'],['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','@'],['X','@','X','X','X','X'],['X','X','X','@','X','X']]
board2 = [['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','X'],['X','X','X','X','X','X'],['X','X','X','X','@','X'],['X','@','X','X','X','X']]
allBoards = [board1, board2]
def printBoard(playBoard):
    for count, ele in enumerate(playBoard):
        print(count, ele)

def scissors(playBoard, ind_x, ind_y, k):
    newboard = playBoard
    fail = -1

    #x coord of position for scissors
    row = playBoard[ind_x]
    #y coord of position for scissors
    col = row[ind_y]
    vertex = playBoard[ind_x][ind_y]
    if k >= 0:
        if vertex == '@' or newboard[ind_x][ind_y+1] == '@':
            print("0")
            print(vertex)
            return fail
        elif newboard[ind_x+1][ind_y+1] == '@' or newboard[ind_x+1][ind_y] == '@':
            print("0")
            print(vertex)
            return fail
        elif k > 1:
            newboard[ind_x][ind_y] = '#'
            newboard[ind_x][ind_y+1] = '#'
            print(vertex)
            if newboard[ind_x+1][ind_y] != '@':
                print("3")
            if newboard[ind_x][ind_y+1] != '@':
                print("4")
                print(f'k is {k}')
                print(newboard)
                newboard = scissors(newboard, ind_x+1, ind_y, k-1)
            else:
                return fail
        else:
            newboard[ind_x][ind_y] = '#'
            newboard[ind_x][ind_y+1] = '#'
            print(vertex)
            if newboard[ind_x+1][ind_y] != '@':
                print("3")
                print("4")
                print(f'k is {k}')
                if k == 0:
                    print(newboard)
                    return newboard
                else:
                    newboard = scissors(newboard, ind_x+1, ind_y, k-1)
            else:
                return fail
    return newboard
def presentBox(playBoard, ind_x, ind_y, k):
    newboard = playBoard
    fail = -1
    vertex = playBoard[ind_x][ind_y]
    if k >= 0:
        if vertex == '@' or vertex == '#':
            return fail
        elif newboard[ind_x][ind_y+1] == '@' or newboard[ind_x][ind_y+1] == '#':
            return fail
        else:
            newboard[ind_x][ind_y] = '!'
            newboard[ind_x][ind_y+1] = '!'
            if newboard[ind_x+1][ind_y] != '@' or newboard[ind_x+1][ind_y] != '#':
                print("3")
                print("4")
                print(f'k is {k}')
                if k == 0:
                    return newboard
                else:
                    newboard = scissors(newboard, ind_x+1, ind_y, k-1)
            else:
                return fail
    else:
        return newboard
    return newboard     
def generateboard():
    ind_x = random.randrange(0,3)
    ind_y = random.randrange(0,4)
    print(ind_x, ind_y)
    num = random.randrange(0,1)
    playBoard = allBoards[num]
    printBoard(playBoard)
    # k == size of the box
    k = 2
    scissorsVar = scissors(playBoard, ind_x, ind_y, k)
    iter = 0
    while iter == 0:
        #-1 = vertex is equal to @
        if scissorsVar == -1:
            ind_x = random.randrange(0,3)
            ind_y = random.randrange(0,4)
            print(ind_x, ind_y)
            playBoard = allBoards[num]
            scissorsVar = scissors(playBoard, ind_x, ind_y, k)

        else:
            iter = 1

    playBoard = scissorsVar
    printBoard(playBoard)



#Generate present 2x2


#generate faux if it lands on num

def main():
    generateboard()



main()
