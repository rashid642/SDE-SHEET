class Solution {
public:
    ListNode* rotateRiaght(ListNode* head, int k) {
         if(head==NULL)return head;
                
        int count=0;
        int len=0;
        ListNode * tempH=head;
        while(tempH!=NULL){
            len++;
            tempH=tempH->next;
        }
        if(len==0 || k==0)return head;
        
        k=k%len;
        
        while(count<k){
        ListNode * temp=head;
        ListNode * tempN=head->next;
            while(tempN->next!=NULL){
                temp=temp->next;
                tempN=tempN->next;
            }
            temp->next=NULL;
            tempN->next=head;
            head=tempN;
            count++;
        }
        return head;
    }
};

//optimized

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)return head;
        int len=1;
        ListNode* cur=head;
        while(cur->next && ++len){
            cur=cur->next;
        }
        cur->next=head;
        k=k%len;
        k=len-k;
        while(k--)cur=cur->next;
        head=cur->next;
        cur->next=NULL;
        return head;
    }
};