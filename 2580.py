import time

def zeroLocation():
    global a
    result = []
    for i in range(0,9):
        for j in range(0,9):
            if a[i][j] == 0:
                result.append(i*9 + j)

    return result

# def colCheck(row, col):
#     global a
#     result = set()
#     for i in range(0,9):
#         result.add(a[i][col])

#     return result

# def squareCheck(row, col):
#     global a
#     result = set()
#     boxRow = (row // 3) * 3
#     boxCol = (col // 3) * 3

#     for i in range(boxRow, boxRow+3):
#         for j in range(boxCol, boxCol+3):
#             result.add(a[i][j])

#     return result

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



a = [[0, 3, 5, 4, 6, 9, 2, 7, 8],
[7, 8, 2, 1, 0, 5, 6, 0, 9],
[0, 6, 0, 2, 7, 8, 1, 3, 5],
[3, 2, 1, 0, 4, 6, 8, 9, 7],
[8, 0, 4, 9, 1, 3, 5, 0, 6],
[5, 9, 6, 8, 2, 0, 4, 1, 3],
[9, 1, 7, 6, 5, 2, 0, 8, 0],
[6, 0, 3, 7, 0, 1, 9, 5, 2],
[2, 5, 8, 3, 9, 4, 7, 6, 0]]
start = time.time()
# a = []
c = False
# for i in range(0,9):
#     a.append([])
#     b = input().split(' ')
#     for j in range(0,9):
#         a[i].append(int(b[j]))

locations = zeroLocation()
proccess(0)
print("time : ", time.time() - start)
