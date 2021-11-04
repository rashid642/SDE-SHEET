class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            if(fast==NULL||fast->next==NULL)return false;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        return true;
    }
};