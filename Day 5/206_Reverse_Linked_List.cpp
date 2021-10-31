class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* curnext;
        while(cur->next!=NULL){
            curnext=cur->next;
            cur->next=prev;
            prev=cur;
            cur=curnext;
        }
        cur->next=prev;
        return cur;
    }
};