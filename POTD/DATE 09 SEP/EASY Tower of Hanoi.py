def towerOfHanoi(n):

    moves = []

    

    def solve_hanoi(n, source, target, auxiliary):

        if n == 1:

            moves.append([source, target])

            return

        solve_hanoi(n - 1, source, auxiliary, target)

        moves.append([source, target])

        solve_hanoi(n - 1, auxiliary, target, source)

    

    solve_hanoi(n, 1, 3, 2) 

    return moves
