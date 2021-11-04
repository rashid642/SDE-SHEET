class Solution {
public:
    int length(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return 1+length(head->next);
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int ind=len-n+1;
        if(ind==1){
            return head->next;
        }
        ListNode* temp=head;
        ListNode* tempN=head->next;
        while(ind-2>0){
            temp=temp->next;
            tempN=temp->next;
            ind--;
        }
        if(tempN==NULL || tempN->next==NULL ){
            temp->next=NULL;
            return head;
        }
        temp->next=tempN->next;
        return head;
    }
};

//optimized

class Solution {
public: 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};