

def proccess(number):
    global board

    for i in range (1,9):
        board[number][i] = board[number-1][i+1] + board[number-1][i-1]
    board[number][9] = board[number-1][8]
    board[number][0] = board[number-1][1]



board = [[]]
size = int(input())

board.append([0,0,0,0,0,0,0,0,0,0])
for i in range(1,10):
    board[1][i] = 1

for i in range(2,size+1):
    board.append([0,0,0,0,0,0,0,0,0,0])
    proccess(i)

result = 0

for i in range(0,10):
    result = result + board[size][i]

print(result % 1000000000)