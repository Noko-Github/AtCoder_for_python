x = int(input())

s = 0
for i, a in enumerate(range(1, x+1), start=1):
    s += a
    if s >= x:
        print(i)
        exit()

exit()
