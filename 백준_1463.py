def mini(number1, number2): return (number1) if number1 < number2 else (number2)
def minii(number1, number2, number3): return mini(mini(number1, number2), number3)

def do(number):
    for i in range(1, number):
        proccess(i)
    return proccess(number)

def proccess(number):
    global board
    global size
    
    if number == 1:
        return 0
    
    if board[number] is not False:
        return board[number]

    else:
        if number % 3 == 0 and number % 2 == 0:
            number1= proccess(number // 3) + 1
            number2= proccess(number // 2) + 1
            number3 = proccess(number - 1) + 1
            board[number] = minii(number1, number2, number3)
        elif number % 3 == 0:
            number1= proccess(number // 3) + 1
            number2 = proccess(number - 1) + 1
            board[number] = mini(number1, number2)
        elif number % 2 == 0:
            number1= proccess(number // 2) + 1
            number2 = proccess(number - 1) + 1
            board[number] = mini(number1,number2)
        else:
            board[number] = proccess(number-1) + 1
        return board[number]


size = int(input())
board = [False] * (size + 1)
print(do(size))