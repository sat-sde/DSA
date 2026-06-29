class LRUCache {
public:
    class node{
       public:
       int key;
       int val;
       node* prev;
       node* next;

       node(int _key,int _val){
        key=_key;
        val=_val;
       }
    };



    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    int cap;
    unordered_map<int,node *>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head->next=tail;
        tail->prev=head;
    }

    void deletenode(node* curr){
        node* prevnode=curr->prev;
        node* afternode=curr->next;
        prevnode->next=afternode;
        afternode->prev=prevnode;
    }

    void insertafterhead(node* curr){
        node* currafterhead=head->next;
        head->next=curr;
        curr->next=currafterhead;
        curr->prev=head;
        currafterhead->prev=curr;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        node* curr=mpp[key];
        deletenode(curr);
        insertafterhead(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if((mpp.find(key)!=mpp.end())){
            node* curr=mpp[key];
            curr->val=value;
            deletenode(curr);
            insertafterhead(curr);
        }else{
            if(mpp.size()==cap){
                node* temp=tail->prev;
                mpp.erase(temp->key);
                deletenode(temp);
            }
            node* curr=new node(key,value);
            mpp[key]=curr;
            insertafterhead(curr);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */