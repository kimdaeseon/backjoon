
def proccess(number):
    for i in range(3, number):
        calc(i)
    return calc(number)

def calc(number):
    global board

    if number == 1: return 1
    if number == 2: return 2

    if board[number] is not False: return board[number]
    else: 
        board[number] = (calc(number -1) + calc(number -2))%15746
        return board[number]



board = [False] * 1000001

number = int(input())
print(proccess(number))
