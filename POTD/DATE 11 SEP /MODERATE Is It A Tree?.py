from sys import stdin, setrecursionlimit

setrecursionlimit(10 ** 7)


def dfs(node, vis, parent, adj, par):
    vis[node] = 1
    parent[node] = par

    for it in adj[node]:
        if not vis[it]:
            b = dfs(it, vis, parent, adj, node)
            if b:
                return True
        elif parent[node] != it:
            return True

    return False

def isTree(adj, V):
    vis = [0] * V
    parent = [0] * V

    b = dfs(0, vis, parent, adj, -1)
    if b:
        return False

    if any(it == 0 for it in vis):
        return False

    return True




















def takeInput():
    n_x = stdin.readline().strip().split(" ")
    V = int(n_x[0].strip())
    E = int(n_x[1].strip())

    #  creating the adj list
    adj = [[] for i in range(V + 1)]

    # Taking edges as input
    for i in range(E):
        n_x = n_x = stdin.readline().strip().split(" ")
        fv = int(n_x[0].strip())
        sv = int(n_x[1].strip())
        adj[fv].append(sv)
        adj[sv].append(fv)

    return adj, V, E


# main

adj, V, E = takeInput()
flag = isTree(adj, V)
if (flag):
    print("True")
else:
    print("False")
