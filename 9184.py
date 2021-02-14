
def w(a,b,c):
    global board


    if a <= 0 or b <= 0 or c <= 0:
        return 1
    
    if a > 20 or b > 20 or c > 20:
        return w(20,20,20)

    if board[a][b][c] is not False:
            return board[a][b][c]

    if a < b and b <c:
        board[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return board[a][b][c]
    
    else:
        board[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return board[a][b][c]

board = [[[False for col in range(21)] for row in range(21)] for height in range(21)]

while(True):
    lines = input()
    lines = lines.split(' ')
    if int(lines[0]) == -1 and int(lines[1]) == -1 and int(lines[2]) == -1:
        break
    print("w(", lines[0], ", ", lines[1], ", ", lines[2], ") = ", w(int(lines[0]), int(lines[1]), int(lines[2])), sep='')