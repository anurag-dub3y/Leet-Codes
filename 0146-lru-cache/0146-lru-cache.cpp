struct DLL{
    public:
    int key;
    int val;
    DLL *next;
    DLL *prev;
    DLL(){
        key = -1;
        val = -1;
        next = NULL;
        prev = NULL;
    }
    DLL(int key,int val){
        this->key =key;
        this->val = val;
        next =NULL;
        prev = NULL;
    }
};
class LRUCache {
    unordered_map<int,DLL*> mp;
    int cap = 0;
    DLL *head = new DLL();
    DLL *tail = new DLL();
public:

    LRUCache(int capacity) {
        
        head->next = tail;
        tail->prev = head;
        cap =capacity;
    }
    
    int get(int key) {
       if(mp.find(key)!=mp.end()){
           DLL *node = mp[key];
           delNode(node);
           insertNode(node);
           return node->val;
       } else{
           return -1;
       }
    }

    void delNode(DLL *node){
        DLL *temp = node->next;
        DLL *tempPrev = node->prev;
        temp->prev = tempPrev;
        tempPrev->next = temp;
    }

    void insertNode(DLL *node){
        DLL* temp = head->next;
        node->next = temp;
        head->next = node;
        node->prev = head;
        temp->prev = node;
    }
    
    void put(int key, int value) {
        DLL *node = new DLL(key,value);
        if(mp.find(key)!=mp.end()){
            delNode(mp[key]);
        }
        mp[key] = node;
        insertNode(node);
        if(mp.size()>cap){
            int delKey = (tail->prev)->key;
            mp.erase(delKey);
            tail->prev = tail->prev->prev;
            
            tail->prev->next = tail;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */