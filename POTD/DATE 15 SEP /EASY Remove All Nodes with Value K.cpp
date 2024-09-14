Node* removeNodes(Node* head, int k) {
    while(head!=NULL && head->data==k) {
        head=head->next;
    }
    Node* slow=NULL;
    Node* fast=head;
    while(fast!=NULL) {
        if(fast->data==k) {
            Node* t=fast;
            slow->next=t->next;
            fast=fast->next;
        } else {
            slow=fast;
            fast=fast->next;
        }
    }
    return head;
}
