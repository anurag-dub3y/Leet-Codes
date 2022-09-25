class MyCircularDeque {
private:
    vector<int> q;
    int head=0, end=0, qsize=0, vsize=0;
    
public:
    MyCircularDeque(int k) {
        vsize=k;
        q.resize(k);
    }
    
    bool insertFront(int value) {
        if(isFull()){ return false; }
        if(isEmpty()){
            head=0; end=0;
            q[head]=value;
            qsize++;
            return true;
        }
        qsize++;
        head=(head-1+vsize)%vsize;
        q[head]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){ return false; }
        if(isEmpty()){
            head=end=0;
            q[head]=value;
            qsize++;
            return true;
        }
        qsize++;
        end=(end+1)%vsize;
        q[end]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){ return false; }
        head=(1+head)%vsize;
        qsize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){ return false; }
        end=(end-1+vsize)%vsize;
        qsize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){ return -1; }
        return q[head];
    }
    
    int getRear() {
        if(isEmpty()){ return -1; }
        return q[end];
    }
    
    bool isEmpty() {
        return qsize==0;
    }
    
    bool isFull() {
        return qsize==vsize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */