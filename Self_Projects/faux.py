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
# todo: make a used array for keeping track of where we have been so we dont possibly try the same vertex twice, 
# this would only be an issue in very complex boards but its still useful for efficiency

#urgent
#0 ['X', 'X', 'X', 'X', 'X', 'X']
#1 ['X', 'X', '@', 'X', 'X', 'X']
#2 ['#', '!', '!', 'X', '@', '#']
#3 ['#', '!', '!', 'X', 'X', '#']
#4 ['#', '@', 'X', 'X', 'X', '#']
#5 ['X', 'X', 'X', '@', 'X', 'X']
# wtf???????????????? out of bounds error somehwere here, maybe try throwing and trying to cathc out of bounds stuff???


board1 = [['X','X','X','X','X','X'],['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','@'],['X','@','X','X','X','X'],['X','X','X','@','X','X']]
board2 = [['X','X','@','X','X','X'],['X','X','X','X','@','X'],['X','X','X','X','X','X'],['X','X','X','X','X','X'],['X','X','X','X','@','X'],['X','@','X','X','X','X']]
allBoards = [board1, board2]
#list of what you dont what to overwrite
nonos = ['@', '#', '!']
def printBoard(playBoard):
    for count, ele in enumerate(playBoard):
        print(count, ele)
        
def bounds(x, y, playBoard, type):
    #the type var tells whether it is 0, for rectangle (scissors) or 1, for a square (present)

    #tells eiterh scissors or present or even faux selector where it can build, either left or right, up or down
    #possibly could return a list first val being wther it can go left or right and 2nd val being whethere up or down
    #returns -1 if it is a failed vertex, 0 if it is a build right2 down1 and 1 if it is a build right2 up1 case, 2 if it is build left2 and down1 and 3 if build left2 and up1, 
    #returns 4 if build right1 down2, 5 if build right1 up3, 6 if build left1 down3, 7 if build left1 up3
    vertex = playBoard[x][y]
    if vertex in nonos:
        print("0")
        print(vertex)
        return -1
    #cases where x is on far right and we are building to horizontally 3x2
    if (x + 1) < 6 and playBoard[x+1][y] not in nonos:
        #x is on the far right
        if type == 0 and (y + 2) < 6 and playBoard[x][y+1] not in nonos and playBoard[x][y+2] not in nonos and playBoard[x+1][y+1] not in nonos and playBoard[x+1][y+2] not in nonos :
            #building to the right down from the top left corner a 3x2 rectangle
            return 0
        elif type == 0 and (y - 2) >= 0 and playBoard[x][y-1] not in nonos and playBoard[x][y-2] not in nonos and playBoard[x+1][y-1] not in nonos and playBoard[x+1][y-2] not in nonos :
            #building to the right up from the top left corner a 3x2 rectangle
            return 1
            
        #now for the square checks
        if type == 1 and (y + 1) < 6 and playBoard[x][y+1] not in nonos and playBoard[x+1][y+1] not in nonos :
            #building to the right down from the top left corner a 3x2 rectangle
            return 0
        elif type == 1 and (y - 1) >= 0 and playBoard[x][y-1] not in nonos and playBoard[x+1][y-1] not in nonos:
            #building to the right up from the top left corner a 3x2 rectangle
            return 1

    if (x-1) >= 0 and playBoard[x-1][y] not in nonos :
        #case where x is on far left
        if type == 0 and (y + 2) < 6 and playBoard[x][y+1] not in nonos and playBoard[x][y+2] not in nonos and playBoard[x-1][y+1] not in nonos and playBoard[x-1][y+2] not in nonos :
            #building up and to the right a 3x2 rectangle or 2x2 square
            return 2
        elif type == 0 and (y - 2) >= 0 and playBoard[x][y-1] not in nonos and playBoard[x][y-2] not in nonos and playBoard[x-1][y-1] not in nonos and playBoard[x-1][y-2] not in nonos :
            #building down and to the left a 3x2 rectangle
            return 3
        
        #now for the square checks
        if type == 1 and (y + 1) < 6 and playBoard[x][y+1] not in nonos and playBoard[x-1][y+1] not in nonos :
            #building up and to the right a 3x2 rectangle or 2x2 square
            return 2
        elif type == 1 and (y - 1) >= 0 and playBoard[x][y-1] not in nonos and playBoard[x-1][y-1] not in nonos:
            #building down and to the left a 3x2 rectangle
            return 3

    #case where x is on far right and we are building down 2x3
    if type == 0 and (x+2) < 6 and playBoard[x+2][y] not in nonos  and playBoard[x+1][y] not in nonos :
        if playBoard[x+2][y] not in nonos  and playBoard[x+2][y+1] not in nonos  and playBoard[x+1][y+1] not in nonos  and playBoard[x][y+1] not in nonos :
            #building to the right and down from the top left corner a 2x3 rectangle
            return 4
        elif playBoard[x+2][y] not in nonos  and playBoard[x+2][y-1] not in nonos  and playBoard[x+1][y-1] !='@'and playBoard[x][y-1] not in nonos :
            #building to the right and up from the top left corner a 2x3 rectangle
            return 5
    if type == 0 and (x-2) >=0 and playBoard[x-2][y] not in nonos and playBoard[x+1][y] not in nonos :
        if playBoard[x-2][y+1] not in nonos  and playBoard[x-1][y+1] not in nonos and playBoard[x][y+1] not in nonos :
            #building down and to the left  corner a 2x3 rectanlge
            return 6
        elif playBoard[x-2][y-1] not in nonos  and playBoard[x-2][y-1] not in nonos  and playBoard[x][y-1] not in nonos :
            #building up and to the left  corner a 2x3 rectanlge
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
    #print(bounds(ind_x, ind_y, newboard, 0))
    if k >= 0:
        #if starting point vertex is a unplaceable or if 
        if bounds(ind_x, ind_y, newboard, 0) < 0:
            #print("0")
            #print(vertex)
            return fail
        #i hate this, surely the 2x2 will look nicer 
        bounds(ind_x, ind_y, newboard, 0)
        match(bounds(ind_x, ind_y, newboard, 0)):
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

    #x coord of position for scissors
    row = playBoard[ind_x]
    #y coord of position for scissors
    col = row[ind_y]
    vertex = playBoard[ind_x][ind_y]
    #print(bounds(ind_x, ind_y, newboard))
    if k >= 0:
        #if starting point vertex is a unplaceable or if 
        if bounds(ind_x, ind_y, newboard,1) < 0:
            #print("0")
            #print(vertex)
            return fail
        #i hate this, surely the 2x2 will look nicer 
        bounds(ind_x, ind_y, newboard,1)
        match(bounds(ind_x, ind_y, newboard,1)):
            #horizontal fill 
            case 0:
                newboard[ind_x][ind_y] = '!'
                newboard[ind_x][ind_y+1] = '!'
                newboard[ind_x+1][ind_y] = '!'
                newboard[ind_x+1][ind_y+1] = '!'
            case 1:
                newboard[ind_x][ind_y] = '!'
                newboard[ind_x][ind_y-1] = '!'
                newboard[ind_x+1][ind_y] = '!'
                newboard[ind_x+1][ind_y-1] = '!'
            case 2:
                newboard[ind_x][ind_y] = '!'
                newboard[ind_x][ind_y+1] = '!'
                newboard[ind_x-1][ind_y] = '!'
                newboard[ind_x-1][ind_y+1] = '!'
            case 3:
                newboard[ind_x][ind_y] = '!'
                newboard[ind_x][ind_y-1] = '!'
                newboard[ind_x-1][ind_y] = '!'
                newboard[ind_x-1][ind_y-1] = '!'
            case _:
                #print("0")
                #print(vertex)
                return fail
    return newboard     
def generateboard():
    ind_x = random.randrange(0,5)
    ind_y = random.randrange(0,5)
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
            ind_x = random.randrange(0,5)
            ind_y = random.randrange(0,5)
            #print(ind_x, ind_y)
            
            playBoard = allBoards[num]
            scissorsVar = scissors(playBoard, ind_x, ind_y, k)
        else:
            iter = 1
    iter = 0
    playBoard = scissorsVar
    printBoard(playBoard)
    ind_x = random.randrange(0,5)
    ind_y = random.randrange(0,5)
    squareVar = presentBox(playBoard, ind_x, ind_y,k)
    while iter == 0:
        #-1 = vertex is equal to @
        if squareVar == -1:
            ind_x = random.randrange(0,5)
            ind_y = random.randrange(0,5)
            #print(ind_x, ind_y)
            playBoard = allBoards[num]
            squareVar = presentBox(playBoard, ind_x, ind_y, k)
        else:
            iter = 1
    #boardTest = allBoards[0]
    #print(bounds(0, 0, boardTest), "HELP")

    playBoard = squareVar
    printBoard(playBoard)
    



#Generate present 2x2


#generate faux if it lands on num

def main():

    generateboard()



main()
