n = int(input())
num = list(map(int, input().split()))

count = 0
while True:
    odd_flag = False
    for value in num:
        if value % 2 != 0:
            odd_flag = True
    if odd_flag:
        break
    count += 1
    new_num = [value / 2 for value in num]
    num = new_num
print(count)
