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