Node* deleteNode(Node *head,int x)
{
    if(head == NULL) return head;
    if(x == 1) return head->next;
    x = x - 2;
    Node* temp = head;
    while(temp != NULL && x--) temp = temp->next;
    if(temp == NULL) return head;
    temp->next = temp->next->next;
    return head;
}