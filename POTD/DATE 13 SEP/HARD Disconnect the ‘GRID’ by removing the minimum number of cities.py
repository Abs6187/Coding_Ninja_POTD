def dfs(x, y, grid):
    global seen
    dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    n = len(grid)
    m = len(grid[0])
    seen[x][y] = 1
    for i in range(4):
        newX = x + dir[i][0]
        newY = y + dir[i][1]
        if (newX >= 0 and newX < n and newY >= 0 and newY < m):
            if (grid[newX][newY] and not seen[newX][newY]):
                dfs(newX, newY, grid)

def isDisconnected(grid, n, m):
    count = 0
    global seen
    seen = []
    for i in range(n):
        temp = [False] * m
        seen.append(temp)
    for i in range(n):
        for j in range(m):
            if (grid[i][j] and not seen[i][j]):
                count += 1
                if (count > 1):
                    return True
                dfs(i, j, grid)
    if (count == 0):
        return True
    return False

def minCities(grid, n, m):
    if (isDisconnected(grid, n, m)):
        return 0
    for i in range(n):
        for j in range(m):
            if (grid[i][j]):
                grid[i][j] = 0
                if (isDisconnected(grid, n, m)):
                    return 1
                grid[i][j] = 1
    return 2
