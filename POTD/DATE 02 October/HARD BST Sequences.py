# LAST QUESTION STREAK ENDED BYE FOR NOW
from typing import List

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def BSTSequence(node: TreeNode) -> List[List[int]]:
    sequences = []
    if node is None:
        sequences.append([])
        return sequences

    prefix = [node.data]
    leftSequences = BSTSequence(node.left)
    rightSequences = BSTSequence(node.right)

    for leftSeq in leftSequences:
        for rightSeq in rightSequences:
            merged = []
            mergeSequences(leftSeq, rightSeq, prefix, merged)
            sequences.extend(merged)

    return sequences

def mergeSequences(leftSeq: List[int], rightSeq: List[int], prefix: List[int], merged: List[List[int]]):
    if not leftSeq and not rightSeq:
        merged.append(list(prefix))
        return

    if leftSeq:
        leftValue = leftSeq.pop(0)
        prefix.append(leftValue)
        mergeSequences(leftSeq, rightSeq, prefix, merged)
        prefix.pop()
        leftSeq.insert(0, leftValue)

    if rightSeq:
        rightValue = rightSeq.pop(0)
        prefix.append(rightValue)
        mergeSequences(leftSeq, rightSeq, prefix, merged)
        prefix.pop()
        rightSeq.insert(0, rightValue)
