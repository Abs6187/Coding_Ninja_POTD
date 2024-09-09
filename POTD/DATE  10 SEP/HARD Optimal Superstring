def merge(a, b):
    n, m = len(a), len(b)
    idx = 0
    for length in range(1, min(n, m) + 1):
        if a[n-length:] == b[:length]:
            idx = length
    return b[idx:]

def solve(words, prev, mask, n, req, dp):
    if dp[prev][mask] != "":
        return dp[prev][mask]
    
    res = ""
    minLen = float('inf')
    
    for i in range(n):
        if mask & (1 << i):
            continue
        
        temp = req[prev][i] + solve(words, i, mask | (1 << i), n, req, dp)
        
        if len(temp) < minLen:
            minLen = len(temp)
            res = temp
    
    dp[prev][mask] = res
    return res

def optimalSuperstring(words, n):
    req = [["" for _ in range(n)] for _ in range(n)]
    dp = [["" for _ in range(1 << (n+1))] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            req[i][j] = merge(words[i], words[j])
    
    ans = ""
    minLen = float('inf')
    
    for i in range(n):
        temp = words[i] + solve(words, i, 1 << i, n, req, dp)
        if len(temp) < minLen:
            minLen = len(temp)
            ans = temp
    
    return len(ans)
