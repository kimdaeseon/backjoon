def maxi(number1, number2): return (number1) if number1 > number2 else (number2)
def maxii(number1, number2, number3): return maxi(maxi(number1, number2), number3)

def proccess():

    global height

    for i in range(height -1, -1, -1):
        for j in range (0, i +1):
            calc(i, j)
    return calc(0, 0)

def calc(size, index):

    global height
    global board
    global tree

    if size == height:
        return 0
    
    if board[size][index] is not False:
        return board[size][index]

    else:
        a = calc(size + 1, index) + tree[size][index]
        b = calc(size + 1, index + 1) + tree[size][index]
        board[size][index] = maxi(a, b)
        return board[size][index]

height = int(input())

board = [False] * height
tree = [0] * height
for i in range (0, height):
    line = input()
    line = line.split(' ')
    board[i] = []
    tree[i] = []
    for j in range(0, i + 1):
        tree[i].append(int(line[j]))
        board[i].append(False)

print(proccess())