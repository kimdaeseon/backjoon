import time

def zeroLocation():
    global a
    result = []
    for i in range(0,9):
        for j in range(0,9):
            if a[i][j] == 0:
                result.append(i*9 + j)

    return result

def check(number):
    global a
    row = number // 9
    col = number % 9
    r1 = set(a[row])
    # r2 = colCheck(row, col)
    for i in range(0,9):
        r1.add(a[i][col])
    # r3 = squareCheck(row, col)
    boxRow = (row // 3) * 3
    boxCol = (col // 3) * 3

    for i in range(boxRow, boxRow+3):
        for j in range(boxCol, boxCol+3):
            r1.add(a[i][j])
    result = {1,2,3,4,5,6,7,8,9} - r1

    return result

def proccess(nLocation):
    global c
    global locations
    global a
    if c:
        return
    if (len(locations) == nLocation) and not c:
        for i in range(0,9):
            print(*a[i])
        c = True
        return
    promissing = check(locations[nLocation])
    if promissing != set():
        while (promissing != set()) and not c:
            value = promissing.pop()
            a[locations[nLocation] // 9][locations[nLocation] % 9] = value
            proccess(nLocation+1)
            a[locations[nLocation] // 9][locations[nLocation] % 9] = 0
    return



a = []
c = False
for i in range(0,9):
    a.append([])
    b = input().split(' ')
    for j in range(0,9):
        a[i].append(int(b[j]))

locations = zeroLocation()
proccess(0)
