def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


if __name__ == '__main__':
    n, x = map(int, input().split())
    X = list(map(int, input().split()))

    X = sorted(X)

    if n == 1:
        print(abs(X[0] - x))
        exit()

    diff = []
    for i in range(n):
        diff.append(abs(x-X[i]))

    ans = 0
    if (len(diff) == 1):
        print(diff[0])
        exit()
    else:
        ans = gcd(diff[0], diff[1])
        for i in range(2, len(diff)):
            ans = gcd(ans, diff[i])

        print(ans)
