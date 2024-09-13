from typing import *


def findNumber(n):
    arr = [0, 1, 2, 3, 4, 5]
    curr = 1
    ans = 0
    n = n - 1
    while n:
        ans = arr[n % 6] * curr + ans
        n //= 6
        curr *= 10
    return ans



