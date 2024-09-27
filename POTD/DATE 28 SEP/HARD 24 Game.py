import itertools
import math

def find24(vec):
    # When only one element is left, check if it is close to 24.
    if len(vec) == 1:
        return math.isclose(vec[0], 24.0, abs_tol=1e-7)

    operations = ['+', '-', '*', '/']

    # Try every pair of numbers and apply all operations
    for i in range(len(vec)):
        for j in range(len(vec)):
            if i == j:
                continue

            # Create a new list excluding the selected pair (i, j)
            res = [vec[k] for k in range(len(vec)) if k != i and k != j]

            for op in operations:
                if (op == '+' or op == '*') and i > j:
                    # No need to re-calculate for commutative operations
                    continue
                if op == '/' and vec[j] == 0:
                    continue

                if op == '+':
                    res.append(vec[i] + vec[j])
                elif op == '-':
                    res.append(vec[i] - vec[j])
                elif op == '*':
                    res.append(vec[i] * vec[j])
                elif op == '/':
                    res.append(vec[i] / vec[j])

                # Recursively call the function with the new result
                if find24(res):
                    return True

                # Remove the last result before the next operation
                res.pop()

    return False

def judge(nums):
    # Convert the integers into a list of floats
    vec = [float(num) for num in nums]
    return find24(vec)
