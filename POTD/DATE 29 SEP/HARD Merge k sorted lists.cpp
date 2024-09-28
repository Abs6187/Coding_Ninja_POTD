#include <bits/stdc++.h>

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
        
        //insert all elements from all lists in priority queue
        for (Node* list : listArray) {
            while (list != nullptr) {
                pq.push(list->data);
                list = list->next;
            }
        }
        
        Node dummy;
        Node* tail = &dummy;
        
        //extract elements from the priority queue and form sorted list
        while (!pq.empty()) {
            tail->next = new Node(pq.top());
            pq.pop();
            tail = tail->next;
        }
        
        return dummy.next;
}
