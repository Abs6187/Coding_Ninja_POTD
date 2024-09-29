from typing import List

def crossProduct(arr: List[List[int]]) -> int:
    x1 = arr[1][0] - arr[0][0]
    y1 = arr[1][1] - arr[0][1]
    x2 = arr[2][0] - arr[0][0]
    y2 = arr[2][1] - arr[0][1]
    return x1 * y2 - y1 * x2

def isConvex(points: List[List[int]]) -> bool:
    n = len(points)
    prev = 0
    curr = 0
    for i in range(n):
        temp = [points[i], points[(i + 1) % n], points[(i + 2) % n]]
        curr = crossProduct(temp)
        if curr != 0:
            if curr * prev < 0:
                return False
            else:
                prev = curr
    return True

def isConvexPolygon(points: List[List[int]], n: int) -> bool:
    if isConvex(points):
        return True
    return False
