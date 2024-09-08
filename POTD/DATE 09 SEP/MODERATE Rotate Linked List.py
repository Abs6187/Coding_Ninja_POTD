class Node:
    def __init__(self, val, next=None):
        self.data = val
        self.next = next


def rotate(head: Node, k: int) -> Node:

    # Base condition.
    if head == None:
        return head

    len = 1
    temp = head

    # Calculate length of the linked list.
    while temp.next != None:
        temp = temp.next
        len += 1

    # If k is greater than k bring it in range of 0 - len.
    if len < k:
        k = int(k % len)

    k = len - k

    # Number of rotations are same as len so no change in LL.
    if k == len or k == 0:
        return head

    count = 1
    current = head

    while count < k and current != None:
        current = current.next
        count += 1

    if current == None:
        return head

    # Changing pointers.
    temp.next = head
    head = current.next
    current.next = None
    return head
