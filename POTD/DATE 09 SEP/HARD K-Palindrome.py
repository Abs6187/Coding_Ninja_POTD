def isPalindrome(k: int, s: str) -> bool:

    n=len(s)

    rev=s[::-1]

    dp=[[0]*(n+1)for _ in range (n+1)]

 

    for i in range(1,n+1):

        for j in range(1, n+1):

            if s[i-1]==rev[j-1]:

                dp[i][j]=dp[i-1][j-1]+1

            else:

                dp[i][j]=max(dp[i-1][j],dp[i][j-1])

    lcs_len= dp[n][n]

    return n-lcs_len <= k 
