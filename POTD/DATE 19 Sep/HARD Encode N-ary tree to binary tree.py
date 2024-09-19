# Binary tree node class for reference:
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
        
# Nary tree node class for reference:
class NTreeNode:
    def __init__(self, data):
        self.data = data
        self.child = []

def encode(root):
    # Converts an N-ary tree to a binary tree
    if not root:
        return None

    # Create a binary tree node with the same value as the N-ary tree root
    binaryRoot = BinaryTreeNode(root.data)

    # If there are children, encode the first child as the left node
    if root.child:
        binaryRoot.left = encode(root.child[0])

    # Link remaining siblings to the right of the left node
    currentBinary = binaryRoot.left
    for i in range(1, len(root.child)):
        currentBinary.right = encode(root.child[i])
        currentBinary = currentBinary.right

    return binaryRoot

def decode(binaryRoot):
    # Converts a binary tree back to an N-ary tree
    if not binaryRoot:
        return None

    # Create an N-ary tree node with the same value as the binary tree root
    naryRoot = NTreeNode(binaryRoot.data)

    # Traverse the left nodes, these correspond to the children in the N-ary tree
    currentBinary = binaryRoot.left
    while currentBinary:
        # Decode the current left node and append to the children list
        naryRoot.child.append(decode(currentBinary))
        # Move to the next sibling in the binary tree (right pointer)
        currentBinary = currentBinary.right

    return naryRoot
