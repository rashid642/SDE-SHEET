class node{
    public:
    node* next;
    node* prev;
    int key, val;
    node(int k, int v){
        key = k;
        val = v;
        next=NULL;
        prev=NULL;
    }
};
void insert(node* &head, node* &node){
    head->next->prev = node;
    node->next = head->next;
    head->next = head->next->prev;
    node->prev = head;
}
void deleteTailPrev(node* &tail){
    tail->prev->prev->next = tail;
    tail->prev = tail->prev->prev;
}
void deletenode(node* &nod){
    nod->prev->next = nod->next;
    nod->next->prev = nod->prev;
}
void traversal(node* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }cout<<"NULL"<<endl;
}
class LRUCache {
public:
    int size, cursize;
    map<int,node*> mpp;
    node* head;
    node* tail;
    LRUCache(int capacity) {
        head = new node(0, 0);
        tail = new node(0, 0);
        cursize=0;
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    int get(int key) {
        if(mpp[key]==NULL)return -1;
        int res = mpp[key]->val;
        node* newnode = new node(key, res);
        deletenode(mpp[key]);
        insert(head, newnode);
        mpp[key]=newnode;
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        node* newnode = new node(key, value);
        if(mpp[key]!=NULL){
            mpp[key]->val=value;
            deletenode(mpp[key]);
            insert(head, mpp[key]);
            mpp[key]=head->next;
            return;
        }
        if(size==cursize){
            mpp[tail->prev->key]=NULL;
            deleteTailPrev(tail);
            insert(head, newnode);
        }else{
            insert(head, newnode);
            cursize++;
        }
        mpp[key]=newnode;
    }
};