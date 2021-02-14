def solve(number):
    arr = [0] * 101
    arr[1] = 1
    arr[2] = 1
    arr[3] = 1
    arr[4] = 2
    arr[5] = 2
    for i in range(6, number + 1):
        arr[i] = arr[i - 1] + arr[i - 5]

    return arr[number]


T = int(input())

for i in range(0, T):
    number = int(input())
    print(solve(number))
