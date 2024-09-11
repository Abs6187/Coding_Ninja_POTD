from typing import *


def valid(x, y, n):
    if (x < 0 or y < 0 or x >= n or y >= n):
        return False
    else:
        return True

def game(n, a, o, x, z):
    a[0] -= 1
    a[1] -= 1
    o[0] -= 1
    o[1] -= 1
    x[0] -= 1
    x[1] -= 1
    z[0] -= 1
    z[1] -= 1

    d = [[1, 0], [0, 1]]
    zt = [[n for _ in range(n)] for i in range(n)]

    for time in range(n):
        zt[z[0]][z[1]] = time
        i = int(time % 2)
        dx = z[0] + d[i][0]
        dy = z[1] + d[i][1]
        if (dx >= n or dx < 0):
            d[0][0] *= -1
        if (dy >= n or dy < 0):
            d[1][1] *= -1
        z[0] = z[0] + d[i][0]
        z[1] = z[1] + d[i][1]

    t = [[0 for _ in range(n)] for i in range(n)]
    dir = []

    total = n - 1
    if (a[0] == 0):
        dir = [1, 0]
        total = n - a[0] - 1
    elif (a[0] == n - 1):
        dir = [-1, 0]
        total = a[0]
    elif (a[1] == 0):
        dir = [0, 1]
        total = n - a[1] - 1
    else:
        dir = [0, -1]
        total = a[1]

    dx = [1, 0, -1, 0, -1, -1, 1, 1]
    dy = [0, 1, 0, -1, -1, 1, -1, 1]

    for i in range(total):
        if i == x[0]:
            if (a[0] + a[1]) % 2 == (x[0] + x[1]) % 2:
                return [a[0] + 1, a[1] + 1]

        if i % 4 == 3:
            t[x[0]][x[1]] -= 3
        else:
            t[x[0]][x[1]] += 1

        if i % 4 == 1:
            for k in range(8):
                i1 = x[0] + dx[k]
                j1 = x[1] + dy[k]
                if not valid(i1, j1, n):
                    continue
                t[i1][j1] += 1

        if t[a[0]][a[1]] != 0 or zt[a[0]][a[1]] <= i:
            return [a[0] + 1, a[1] + 1]

        if i % 4 == 1:
            for k in range(8):
                i1 = x[0] + dx[k]
                j1 = x[1] + dy[k]
                if not valid(i1, j1, n):
                    continue
                t[i1][j1] -= 1

        a[0] += dir[0]
        a[1] += dir[1]

    return [-1, -1]
