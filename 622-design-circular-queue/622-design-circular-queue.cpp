class MyCircularQueue {
private:
    vector<int> q;
    int qsize=0, head=0, end=0, vsize=0;
public:
    MyCircularQueue(int k) {
        q.resize(k); vsize=k;
        return;
    }
    
    bool enQueue(int value) {
        if(qsize==vsize){ return false; }
        if(qsize==0){
            head=end=0;
            q[head]=value;
            qsize++;
            return true;
        }
        end++; qsize++;
        end%=vsize;
        q[end]=value;
        return true;
    }
    
    bool deQueue() {
        if(qsize==0){ return false; }
        head=(head+1)%vsize; qsize--;
        return true;
    }
    
    int Front() {
        if(qsize==0){ return -1; }
        return q[head];
    }
    
    int Rear() {
        if(qsize==0){ return -1; }
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */