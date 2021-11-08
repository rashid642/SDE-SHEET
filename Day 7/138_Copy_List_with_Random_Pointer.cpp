//using maps

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h=head;
        unordered_map<Node*,Node*> mpp;
        while(h!=NULL){
            Node* n=new Node(h->val);
            mpp[h]=n;
            h=h->next;
        }
        h=head;
        while(h!=NULL){
            Node* nex=h->next;
            Node* ran=h->random;
            mpp[h]->next=mpp[nex];
            mpp[h]->random=mpp[ran];
            h=h->next;
        }
        return mpp[head];

    }
};

//Optimized

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return head;
        Node* temp=head;
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }else{
                temp->next->random=NULL;
            }
            
            temp=temp->next->next;
        }
        Node* dummy=new Node(0);
        dummy->next=head->next;
        temp=head;
        Node* clone=dummy->next;
        while(clone->next!=NULL){
            Node* tempN=clone->next;
            clone->next=tempN->next;
            temp->next=tempN;
            clone=clone->next;
            temp=temp->next;
        }
        temp->next=NULL;
        clone->next=NULL;
        return dummy->next;
   