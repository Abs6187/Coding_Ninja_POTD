def rotate(head: Node, k: int) -> Node:
    # Write your code here.
    if head is not None and head.next is not None:
        stack = []
        n = 1
        last = head
        while last.next is not None:
            n+=1
            stack.append(last)
            last = last.next
        k = k%n
        if k!=0:
            i = 0
            prev = last
            cur = last
            while i<k:
                i+=1
                prev = cur
                cur = stack.pop(n-2)
                n-=1
            cur.next = None
            last.next = head
            head = prev
    return head
