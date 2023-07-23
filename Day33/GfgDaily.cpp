Node* segregate(Node *head) {
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                if(zeroHead == NULL && zeroTail == NULL){
                    zeroHead = temp;
                    zeroTail = temp;
                }else{
                    zeroTail->next = temp;
                    zeroTail = zeroTail->next;
                }
            }else if(temp->data == 1){
                if(oneHead == NULL && oneTail == NULL){
                    oneHead = temp;
                    oneTail = temp;
                }else{
                    oneTail->next = temp;
                    oneTail = oneTail->next;
                }
            }else{
                if(twoHead == NULL && twoTail == NULL){
                    twoHead = temp;
                    twoTail = temp;
                }else{
                    twoTail->next = temp;
                    twoTail = twoTail->next;
                }
            }
            temp = temp->next;
        }
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        if(zeroTail != NULL){
            ansHead = zeroHead;
            ansTail = zeroTail;
        }
        if(oneTail != NULL){
            if(ansTail == NULL){
                ansHead = oneHead;
                ansTail = oneTail;
            }else{
                ansTail->next = oneHead;
                ansTail = oneTail;
            }
        }
        if(twoTail !=NULL){
            if(ansTail == NULL){
                ansHead = twoHead;
                ansTail = twoTail;
            }else{
                ansTail->next = twoHead;
                ansTail = twoTail;
            }
        }
        ansTail->next = NULL;
        return ansHead;
    }