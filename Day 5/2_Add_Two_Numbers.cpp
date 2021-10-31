class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummyHead=new ListNode(0);
        ListNode * p=dummyHead;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            int sum=carry+x+y;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            p->next=temp;
            p=p->next;
            if(l1!=NULL){l1=l1->next;}
            if(l2!=NULL){l2=l2->next;}
            
        }
        if(carry>0){
          ListNode* temp=new ListNode(carry);
            p->next=temp;  
        }
        return dummyHead->next;
    }
};