n, m = map(int, (input().split()))
x = list(map(int, input().split()))
x = sorted(x)
diff = []
for i in range(m-1):
    diff.append(x[i+1] - x[i])

diff = sorted(diff, reverse=True)

dist = x[-1] - x[0]
if dist < n:
    print(0)
    exit()

if m < n:
    print(0)
    exit()

for i in range(n-1):
    dist -= diff[i]

print(dist)
