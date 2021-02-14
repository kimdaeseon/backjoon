

def check():

    global operators
    count = 0
    result = []
    for i in operators:
        if i > 0:
            result.append(True)
        else:
            result.append(False)
            count = count + 1
    if count == 4:
        return False
    return result

def calc(operator, index):
    global result
    global numbers

    if operator == 0:
        result = result + numbers[index]
    elif operator == 1:
        result = result - numbers[index]
    elif operator == 2:
        result = result * numbers[index]
    elif operator == 3:
        if result < 0:
            result = result * -1
            result = result // numbers[index]
            result = result * -1
        else:
            result = result // numbers[index]


def proccess(index):

    global size
    global result
    global numbers
    global operators
    global maxi
    global mini
    if index == size:
        if result > maxi:
            maxi = result
        if result < mini:
            mini = result
        return
    promissing = check()
    if promissing is not False:
        for i in range (0, 4):
            if not promissing[i]:
                continue
            elif promissing[i]:
                operators[i] = operators[i] - 1
                temp = result
                calc(i, index)
                proccess(index+1)
                operators[i] = operators[i] + 1
                promissing[i] = False
                result = temp

operators = [0] * 4
numbers = []
maxi = -1000000000
mini = 1000000000

size = int(input())
secondLine = input()
secondLine = secondLine.split(' ')
thirdLine = input()
thirdLine = thirdLine.split(' ')
for i in range(0, size):
    numbers.append(int(secondLine[i]))

for i in range(0, 4):
    operators[i] = int(thirdLine[i])

result = numbers[0]
proccess(1)

print(maxi,mini)