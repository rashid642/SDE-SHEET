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