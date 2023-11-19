Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* start = NULL;
    Node* end = NULL;
    
    while(temp1 !=NULL && temp2 !=NULL){
        if(temp1->data == temp2->data){
            Node* newNode = new Node(temp1->data);
            if(start == NULL){
                start = newNode;
                end = newNode;
            }else{
                end->next = newNode;
                end = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if(temp1 ->data > temp2 ->data){
            temp2 = temp2->next;
        }else{
            temp1 = temp1->next;
        }
    }
    return start;
}