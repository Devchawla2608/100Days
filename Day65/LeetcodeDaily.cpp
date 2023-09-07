class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        dummy->next=head;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        ListNode* n=NULL;
        for(int i=left;i<right;i++){
            n=curr->next;
            curr->next=n->next;
            n->next=prev->next;
            prev->next=n;
        }
        return dummy->next;
    }
};