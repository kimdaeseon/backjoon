def checkData(number):
    result = 0
    if not hasattr(checkData, "Data"):
        checkData.Data = [0] * 1000001

    if checkData.Data[number] != 0:
        return checkData.Data[number]

    else:
        if number == 1:
            result = 1
        elif number == 2:
            result = 2
        else:
            result = checkData(number - 2) + checkData(number - 1)
        checkData.Data[number] = result % 15746
        return result


def solv(number):

    for i in range(1, number + 1):
        if not checkData.Data[i]:
            checkData(i)
    return None


checkData.Data = [0] * 1000001
number = int(input())
solv(number)
print(checkData.Data[number])
