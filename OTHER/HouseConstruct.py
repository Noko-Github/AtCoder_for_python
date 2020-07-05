H, W, K, V = map(int, input().split())

A = [list(map(int, list(input().split()))) for i in range(H)]

# 二次元累積和を生成
dp = [[0 for _ in range(W+1)] for _ in range(H+1)]
tmp = 0
for h in range(H):
    for w in range(W):
        dp[h+1][w+1] = dp[h+1][w] + dp[h][w+1] - dp[h][w] + A[h][w]


# 全ての範囲のパターンを見て、Vを超えているかどうか判定O(W^2*H^2)
ans = 0
for h_from in range(1, H+1):
    for h_to in range(h_from, H+1):
        for w_from in range(1, W+1):
            for w_to in range(w_from, W+1):
                cost = dp[h_to][w_to] - dp[h_to][w_from-1] - \
                    dp[h_from-1][w_to] + dp[h_from-1][w_from-1]
                area = (h_to - h_from + 1) * (w_to - w_from + 1)
                cost += K * area
                if (V >= cost):
                    ans = max(ans, area)

print(ans)
