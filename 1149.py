def mini(number1, number2): return (number1) if number1 < number2 else (number2)
def minii(number1, number2, number3): return mini(mini(number1, number2), number3)

def proccess(number):
    for i in range(1, number):
        calc(i, 0)
        calc(i, 1)
        calc(i, 2)
    
    return minii(calc(number, 0), calc(number, 1), calc(number, 2))

def calc(number, colorOfpriev):
    global board
    global costOfRed
    global costOfGreen
    global costOfBlue
    global cost

    if number == 0: return 0 

    if board[colorOfpriev][number] is not False:
        return board[colorOfpriev][number]
    else:
        a = calc(number -1, (colorOfpriev + 1) % 3) + cost[(colorOfpriev + 1) % 3][number]
        b = calc(number -1, (colorOfpriev + 2) % 3) + cost[(colorOfpriev + 2) % 3][number]
        board[colorOfpriev][number] = mini(a, b)
        return board[colorOfpriev][number]

# 전 집이 빨간색일 때 비용 0
# 전 집이 초록색일 때 비용 1
# 전 집이 파란색일 때 비용 2

board = [[False] * 1001, [False] * 1001, [False] * 1001]
cost = [[0]* 1001, [0]* 1001, [0]* 1001]
numberOfHouse = int(input())

costOfRed = [0] * numberOfHouse
costOfGreen = [0] * numberOfHouse
costOfBlue = [0] * numberOfHouse

for i in range(1, numberOfHouse+1):
    line = input()
    line = line.split(' ')
    cost[0][i] = int(line[0])
    cost[1][i] = int(line[1])
    cost[2][i] = int(line[2])

print(proccess(numberOfHouse))