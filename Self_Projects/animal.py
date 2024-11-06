def main():
    starter = input()
    num = input()
    num = int(num)
    animals = []
    out = ''
    for i in range(num):
        ele = input()
        animals.append(ele)
        if animals[i][0] == starter[len(starter)-1]:
            out = animals[i]
        elif out == '':
            out = '?'
    ex = 0
har
    if out != '?':
        for x in range(num):
            if out != animals[x]:
                if out[len(out)-1] != animals[x][0]:
                    ex = 1
                else:
                    ex = 0
    if ex == 1:
        out = out + '!'
    print(out)
    
    
    
main()