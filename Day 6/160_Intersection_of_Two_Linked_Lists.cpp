class Solution {
public:
    int length(ListNode* head){
        if(head==NULL)return 0;
        return 1+length(head->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=length(headA);
        int lenB=length(headB);
        // cout<<lenA<<" "<<lenB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            for(int i=1;i<=diff;i++){
                // cout<<headA->val<<"->";
                headA=headA->next;
            }
        }
        if(lenA<lenB){
            int diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                // cout<<headB->val<<"->";
                headB=headB->next;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};

//another optimized code

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)return NULL;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }
};

//not that optimized but used hashing

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)return NULL;
        set<ListNode*> st;
        while(headA){
            st.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(st.count(headB)>0){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
};