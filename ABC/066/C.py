from collections import deque

n = int(input())
a = list(map(int, input().split()))

d = deque()
for i, value in enumerate(a, start=1):
    if n % 2 == i % 2:
        d.appendleft(value)
    else:
        d.append(value)

for value in d:
    print(f'{value} ', end="")
print()
exit()
