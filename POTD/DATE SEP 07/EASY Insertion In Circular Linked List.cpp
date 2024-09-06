Node* insert(int k, int val, Node *head) {

    

    int count = 1;

    if(k == 0){

        Node* newNode = new Node(val);

        newNode->next = head;

        head = newNode;

        Node* temp = head->next->next;

        while(temp->next!=head->next){

            temp = temp->next;

        }

        temp->next = newNode;

        return head;

    }

    Node* temp = head;

    while(count < k){

        temp = temp->next;

        count++;

    }

 

    Node* newNode = new Node(val);

    newNode->next = temp->next;

    temp -> next = newNode;

    return head;

}
