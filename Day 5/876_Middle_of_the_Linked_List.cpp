class Solution {
public:
    int length(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return 1+length(head->next);
    }
    ListNode* middleNode(ListNode* head) {
        int len=length(head);
        int mid=len/2+1;
        while(mid-1>0){
            head=head->next;
            mid--;
        }
        return head;
    }
};

//optimized

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};