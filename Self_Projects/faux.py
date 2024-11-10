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


#Now start the present case than actually taking inoput from user


#I think x might actually be y and y might atually be x, fuck...

board1 = [['X','X','X','X','X','X'],['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','@'],['X','@','X','X','X','X'],['X','X','X','@','X','X']]
board2 = [['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','X'],['X','X','X','X','X','X'],['X','X','X','X','@','X'],['X','@','X','X','X','X']]
allBoards = [board1, board2]
def printBoard(playBoard):
    for count, ele in enumerate(playBoard):
        print(count, ele)
        
def bounds(x, y, playBoard):
    #tells eiterh scissors or present or even faux selector where it can build, either left or right, up or down
    #possibly could return a list first val being wther it can go left or right and 2nd val being whethere up or down
    #returns -1 if it is a failed vertex, 0 if it is a build right2 down1 and 1 if it is a build right2 up1 case, 2 if it is build left2 and down1 and 3 if build left2 and up1, 
    #returns 4 if build right1 down2, 5 if build right1 up3, 6 if build left1 down3, 7 if build left1 up3
    vertex = playBoard[x][y]
    if vertex == '@':
        print("0")
        print(vertex)
        return -1
    if (x + 1) < 6 and playBoard[x+1][y] != '@':
        #case where x is on far right
        if (y + 2) < 6 and playBoard[x][y+1] != '@'and playBoard[x][y+2] != '@'and playBoard[x+1][y+1] != '@'and playBoard[x+1][y+2] != '@':
            #case where x below is blocked and unplaceable
            return 0
        elif (y - 2) >= 0 and playBoard[x][y-1] != '@'and playBoard[x][y-2] != '@'and playBoard[x+1][y-1] != '@'and playBoard[x+1][y-2] != '@':
            return 1
    if (x-1) >= 0 and playBoard[x-1][y] != '@':
        #case where x is on far left
        if (y + 2) < 6 and playBoard[x][y+1] != '@'and playBoard[x][y+2] != '@'and playBoard[x-1][y+1] != '@'and playBoard[x-1][y+2] != '@':
            #case where x above is blocked and unplaceable
            return 2
        elif (y - 2) >= 0 and playBoard[x][y-1] != '@'and playBoard[x][y-2] != '@'and playBoard[x-1][y-1] != '@'and playBoard[x-1][y-2] != '@':
            return 3
    if(x+2) < 6 and playBoard[x+2][y] != '@' and playBoard[x+1][y] :
        if playBoard[x+2][y] != '@' and playBoard[x+2][y+1] != '@' and playBoard[x+1][y+1] != '@' and playBoard[x][y+1] != '@':
            return 4
        elif playBoard[x+2][y] != '@' and playBoard[x+2][y-1] != '@' and playBoard[x+1][y+1] !='@'and playBoard[x][y-1] != '@':
            return 5
    if (x-2) >=0 and playBoard[x-2][y] != '@'and playBoard[x+1][y] != '@':
        if playBoard[x-2][y+1] != '@' and playBoard[x-1][y+1] != '@'and playBoard[x][y+1] != '@':
            return 6
        elif playBoard[x-2][y-1] != '@' and playBoard[x-2][y-1] != '@' and playBoard[x][y-1] != '@':
            return 7
    else:
        return -1



def scissors(playBoard, ind_x, ind_y, k):
    newboard = playBoard
    fail = -1

    #x coord of position for scissors
    row = playBoard[ind_x]
    #y coord of position for scissors
    col = row[ind_y]
    vertex = playBoard[ind_x][ind_y]
    #print(bounds(ind_x, ind_y, newboard))
    if k >= 0:
        #if starting point vertex is a unplaceable or if 
        if bounds(ind_x, ind_y, newboard) < 0:
            #print("0")
            #print(vertex)
            return fail
        #i hate this, surely the 2x2 will look nicer 
        bounds(ind_x, ind_y, newboard)
        match(bounds(ind_x, ind_y, newboard)):
            #horizontal fill 
            case 0:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x][ind_y+1] = '#'
                newboard[ind_x][ind_y+2] = '#'
                newboard[ind_x+1][ind_y] = '#'
                newboard[ind_x+1][ind_y+1] = '#'
                newboard[ind_x+1][ind_y+2] = '#'
            case 1:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x][ind_y-1] = '#'
                newboard[ind_x][ind_y-2] = '#'
                newboard[ind_x+1][ind_y] = '#'
                newboard[ind_x+1][ind_y-1] = '#'
                newboard[ind_x+1][ind_y-2] = '#'
            case 2:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x][ind_y+1] = '#'
                newboard[ind_x][ind_y+2] = '#'
                newboard[ind_x-1][ind_y] = '#'
                newboard[ind_x-1][ind_y+1] = '#'
                newboard[ind_x-1][ind_y+2] = '#'
            case 3:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x][ind_y-1] = '#'
                newboard[ind_x][ind_y-2] = '#'
                newboard[ind_x-1][ind_y] = '#'
                newboard[ind_x-1][ind_y-1] = '#'
                newboard[ind_x-1][ind_y-2] = '#'
            #now begin the vertical fill
            case 4:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x+1][ind_y] = '#'
                newboard[ind_x+2][ind_y] = '#'
                newboard[ind_x][ind_y+1] = '#'
                newboard[ind_x+1][ind_y+1] = '#'
                newboard[ind_x+2][ind_y+1] = '#'
            case 5:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x+1][ind_y] = '#'
                newboard[ind_x+2][ind_y] = '#'
                newboard[ind_x][ind_y-1] = '#'
                newboard[ind_x+1][ind_y-1] = '#'
                newboard[ind_x+2][ind_y-1] = '#'
            case 6:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x-1][ind_y] = '#'
                newboard[ind_x-2][ind_y] = '#'
                newboard[ind_x][ind_y+1] = '#'
                newboard[ind_x-1][ind_y+1] = '#'
                newboard[ind_x-2][ind_y+1] = '#'
            case 7:
                newboard[ind_x][ind_y] = '#'
                newboard[ind_x-1][ind_y] = '#'
                newboard[ind_x-2][ind_y] = '#'
                newboard[ind_x][ind_y-1] = '#'
                newboard[ind_x-1][ind_y-1] = '#'
                newboard[ind_x-2][ind_y-1] = '#'
            case _:
                #print("0")
                #print(vertex)
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
                #print("3")
                #print("4")
                #print(f'k is {k}')
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
    #print(ind_x, ind_y)
    num = random.randrange(0,1)
    playBoard = allBoards[num]
    #printBoard(playBoard)
    # k == size of the box
    k = 2
    scissorsVar = scissors(playBoard, ind_x, ind_y, k)
    iter = 0
    while iter == 0:
        #-1 = vertex is equal to @
        if scissorsVar == -1:
            ind_x = random.randrange(0,3)
            ind_y = random.randrange(0,4)
            #print(ind_x, ind_y)
            playBoard = allBoards[num]
            scissorsVar = scissors(playBoard, ind_x, ind_y, k)

        else:
            iter = 1
    #boardTest = allBoards[0]
    #print(bounds(0, 0, boardTest), "HELP")

    playBoard = scissorsVar
    printBoard(playBoard)
    



#Generate present 2x2


#generate faux if it lands on num

def main():

    generateboard()

main()
