from os import *
from sys import *
from collections import *
from math import *

class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inorder(root, queue):
    if root is None:
        return

    inorder(root.left, queue)

    queue.append(root)

    inorder(root.right, queue)

def convertInCircularDLL(root):
    if root is None:
        return root
    queue = []

    inorder(root, queue)

    head = queue[0]

    queue.pop(0)

    current = head

    while len(queue) > 0:
        temp = queue[0]
        queue.pop(0)
        current.right = temp
        temp.left = current
        current = current.right

    current.right = head

    head.left = current

    return head
