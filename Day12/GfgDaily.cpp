// Union of Two Linked Lists
// Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> st;
        while(head1 != NULL){
            st.insert(head1->data);
            head1 = head1->next;
        }
        while(head2 != NULL){
            st.insert(head2->data);
            head2 = head2->next;
        }
        Node* newHead = new Node(-1);
        Node* newTail = newHead;
        for(auto it : st){
            Node*  nd = new Node(it);
            newTail->next = nd;
            newTail = newTail->next;
        }
        return newHead->next;
    }