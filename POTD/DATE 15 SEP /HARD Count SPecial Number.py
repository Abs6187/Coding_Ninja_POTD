from collections import deque

def countSpecialNumbers(n):
    i, u, ans = 0, 0, 0
    q = deque()
    for i in range(1, 6):
        q.append(i)
    while q:
        u = q.popleft()
        if u <= n:
            ans += 1
        for i in range(1, 6):
            if u * 10 + i <= n:
                q.append(u * 10 + i)
    return ans
