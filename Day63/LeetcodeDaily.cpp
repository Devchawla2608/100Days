class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* temp = head;
        while(temp != NULL && temp->next != NULL ){
            Node* newNode = new Node(temp->val);
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
            temp = temp->next->next;
        }
        Node* newNode = new Node(temp->val);
        temp->next = newNode;
        newNode->next = NULL;
        temp = head;
        while(temp!= NULL){
            Node* nextNode = temp->next;
            if(temp->random == NULL){
                nextNode->random = NULL;
            }else{
                Node* randomPoint = temp->random;
                nextNode->random = randomPoint->next;
            }
            temp = temp->next->next;
        }
        Node* newHead = new Node(-1);
        Node* newTail = newHead;
        temp = head;
        while( temp != NULL && temp->next != NULL ){
            newTail->next = temp->next;
            temp->next = temp->next->next;
            newTail = newTail->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};