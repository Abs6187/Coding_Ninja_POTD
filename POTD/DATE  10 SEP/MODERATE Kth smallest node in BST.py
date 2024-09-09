from typing import Optional

class TreeNode:
    def __init__(self, data: int):
        self.data = data
        self.left = None
        self.right = None


def kthSmallest(root, k):

 

    count=0

    stack=[]

    cur=root

    

    while cur or stack:

 

        while cur:

            stack.append(cur)

            cur=cur.left

 

        cur=stack.pop()

        count=count+1

        if count==k:

            return cur.data

        cur=cur.right
