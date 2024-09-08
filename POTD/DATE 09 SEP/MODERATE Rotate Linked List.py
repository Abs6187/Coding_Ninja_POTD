def nthNode(head:Node , pos) -> Node:
    temp , cnt = head , 1

    while temp.next:
        if cnt==pos: return temp
        cnt+=1
        temp = temp.next
    return temp
    
def rotate(head: Node, k: int) -> Node:
    if head is None or k==0: return head

    tail , lens = head , 1
    while tail.next is not None: # finding the length of the linked list
        lens+=1
        tail = tail.next

    if k%lens==0: return head

    k = k % lens
    LastNode = nthNode(head,lens-k)
    tail.next = head
    head = LastNode.next
    LastNode.next = None
    
    return head
