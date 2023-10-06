    struct Node* reverseList(struct Node *head)
    {
      Node* first =NULL;
      Node* second = head;
      while(second != NULL){
         Node* temp = second ->next;
         if(temp == NULL) break;
         second->next = first;
         first = second;
         second = temp;
      }
      second ->next = first;
      return second;
    }
    
    void rearrange(struct Node *odd)
    {
        if(odd == NULL || odd->next == NULL) return;
        Node* temp = odd;
        Node* newHead = new Node(-1);
        Node* newTail = newHead;
        while(temp != NULL && temp->next != NULL){
            newTail->next = temp->next;
            temp->next = temp->next->next;
            newTail = newTail->next;
            newTail->next = NULL;
            temp = temp->next;
        }
        Node* reverseHead = reverseList(newHead->next);
        Node* head = odd;
        while(odd->next != NULL)odd = odd->next;
        odd->next = reverseHead;
    }