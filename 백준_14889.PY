def calc():
    global teamA
    global teamB
    global board
    global number
    teamAScore = 0
    teamBScore = 0

    for i in range(0, number):
        for j in range(0, number):
            if i == j:
                continue
            if teamA[i] and teamA[j]:
                teamAScore = teamAScore + int(board[i][j])
            if teamB[i] and teamB[j]:
                teamBScore = teamBScore + int(board[i][j])

    return (teamAScore- teamBScore) if teamAScore > teamBScore else (teamBScore -teamAScore)

def promissing():
    global number
    global people
    index = 0
    result = []
    for i in range(0, len(people)):
        if people[i] == False:
            index = i;
    for i in range(index, len(people)):
        if people[i] == True:
            result.append(i)

    return result

def proccess(num):
    global board
    global number
    global people
    global teamA
    global teamB
    global mini


    if num == number/2:
        value = calc()
        if value < mini:
            mini = value
        return
    promise = promissing()
    if promissing() is not False:
        for i in range(0, len(promise)):
            value = promise.pop(0)
            people[value] = False
            teamA[value] = True
            teamB[value] = False
            proccess(num+1)
            people[value] = True
            teamA[value] = False
            teamB[value] = True

mini = 10000000
number = int(input())
board = []
teamA = [False] * number
teamB = [True] * number
people = [True] * number
for i in range(0, number):
    lines = input()
    lines = lines.split()
    board.append(lines)

proccess(0)

print(mini)
