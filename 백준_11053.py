


inf = -1000
number = int(input())
numbers = input()
numbers = numbers.split(' ')
numbers.insert(0,inf)
result = [inf] * (number + 1)

result[1] = (int)(numbers[1])

for i in range(1,number + 1):
    for j in range(1, i):
        if result[j] == inf:
            break;
        if result[j] < (int)(numbers[i]):
            if (result[j+1] == inf) or (result[j+1] > (int)(numbers[i])):
                result[j+1] = (int)(numbers[i])
    if result[1] > (int)(numbers[i]):
        result[1] = (int)(numbers[i])

for i in range(1, number + 1):
    if result[i] != inf:
        maxi = i;

print(maxi)