class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        stack <int> st;
        for(int i=0;i<len/2;i++){
            st.push(temp->val);
            temp=temp->next;
        }
        if(len%2!=0){
            temp=temp->next;
        }
        while(!st.empty()){
            if(st.top()==temp->val){
                st.pop();
                temp=temp->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//using O(1) space complexity

class Solution {
public:
    void traverse(ListNode* head){
        if(head==NULL)return;
        cout<<head->val<<"->";
        traverse(head->next);
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* Dummy=new ListNode(0);
        Dummy->next=slow->next;
        ListNode* dumnext=Dummy->next;
        ListNode* cur=Dummy->next;
        ListNode* prev=Dummy;
        ListNode* nex;
        while(cur!=NULL){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        dumnext->next=NULL;
        slow->next=prev;
        //traverse(head);
        slow=head;
        while(prev!=NULL){
            if(prev->val!=slow->val)return false;
            prev=prev->next;
            slow=slow->next;
        }
        return true;
    }
};