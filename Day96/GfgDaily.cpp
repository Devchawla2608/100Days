class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* temp = head;
        if(head == NULL) {
            Node* newNode = new Node(data);
            return newNode;
        }
        if(data < head->data){
            Node* newNode = new Node(data);
            newNode->next = head;
            return newNode;
        }
        while(temp != NULL && temp->next !=NULL){
            if(data >= temp->data && data < temp->next->data){
                Node* newNode = new Node(data);
                Node* save = temp->next;
                temp->next = newNode;
                newNode->next = save;
                return head;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
        return head;
    }
};