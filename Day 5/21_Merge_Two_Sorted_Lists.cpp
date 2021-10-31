class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * dummyhead=new ListNode(0);
        ListNode * temp=dummyhead;
        while(l1!=NULL && l2!=NULL){
            
            if(l1->val > l2->val){
                // ListNode * newnode=new ListNode(l2->val);
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
            else{
               // ListNode * newnode=new ListNode(l1->val);
                temp->next=l1;
                temp=temp->next;
                l1=l1->next; 
            }
        }
        if(l1!=NULL){
            temp->next=l1;
            l1=l1->next;
        }
        if(l2!=NULL){
            temp->next=l2;
            // l2=l2->next;
        }
        return dummyhead->next;
    }
};