class Solution {
public:
    int length(ListNode* head){
        if(head==NULL)return 0;
        return 1+length(head->next);
    }
    void traverse(ListNode* head){
        if(head==NULL)return;
        cout<<head->val<<"->";
        traverse(head->next);
    }

    //reverse function
    //1->2->3->4->5->6
    //reverse(3rd node, 3) i.e. 3->4->5->6
    //reverse function returns 5->4->3->6
    //and then attact to 2nd node i.e. 1->2->5->4->3->6

    ListNode* reverse(ListNode* start, int k){
        ListNode* prev=NULL;
        ListNode* cur=start;
        ListNode* nex=NULL;
        for(int i=1;i<=k;i++){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        start->next=cur;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=length(head);
        int cycle=len/k;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* newHead=dummy;
        for(int i=0;i<cycle;i++){
                dummy->next=reverse(dummy->next,k);
                for(int i=0;i<k;i++)dummy=dummy->next;
        }
        return newHead->next;
    }
};