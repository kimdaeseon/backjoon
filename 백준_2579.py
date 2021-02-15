def maxi(number1, number2): return (number1) if number1 > number2 else (number2)
def maxii(number1, number2, number3): return maxi(maxi(number1, number2), number3)



def proccess():
    global score
    global size
    global board

# [][0] == 연속
# [][1] == 비연속

    board[0][0] = 0
    board[0][1] = score[0]

    if size == 1:
        return maxi(board[0][0], board[0][1])
    board[1][0] = score[1] + board[0][1]
    board[1][1] = score[1]


    if size == 2:
        return maxi(board[1][0], board[1][1])

    for i in range (2, size):
        board[i][0] = score[i] + board[i - 1][1]
        board[i][1] = score[i] + maxi(board[i - 2][0], board[i - 2][1])

    return maxi(board[size - 1][0], board[size -1][1])

size = int(input())
score = []
board = []
for i in range (0, size):
    score.append(int(input()))
    board.append([])
    board[i].append(0)
    board[i].append(0)


print(proccess())