from os import *
from sys import *
from collections import *
from math import *

from collections import deque

def countOfNumbers(n):
    count = 0
    q = deque([1])

    while q:
        curr = q.popleft()

        if curr > n:
            break

        count += 1

        q.append(curr * 10)
        q.append(curr * 10 + 1)

    return count

