def isMatch(s, p):
    dp = [[-1] * (len(p) + 1) for _ in range(len(s) + 1)]

    def match(i, j):
        if j < 0:
            return i < 0

        if i < 0:
            if j % 2 == 0:
                return False

            while j > 0:
                if p[j] != '*':
                    return False
                j -= 2

            return True

        if dp[i][j] != -1:
            return dp[i][j]

        if s[i] == p[j] or p[j] == '.':
            return match(i - 1, j - 1)

        dp[i][j] = (p[j] == '*' and (match(i, j - 2) or (s[i] == p[j - 1] or p[j - 1] == '.' and match(i - 1, j))))

        return dp[i][j]

    return match(len(s) - 1, len(p) - 1)
