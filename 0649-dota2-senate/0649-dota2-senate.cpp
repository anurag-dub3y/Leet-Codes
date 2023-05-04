struct circNode {
    int val;
    circNode* next;
    circNode* prev;
    circNode(int v) {
        val = v;
        next = NULL;
        prev = NULL;
    }
};
class circList {
public:
    circList() {size=0; head = NULL; tail = NULL;}
    bool empty() {return size == 0;}
    circNode* push(int val) {
        if(size == 0) {
            head = new circNode(val);
            tail = head;
            tail->next = head;
            head->prev = tail;
            size = 1;
        } else {
            circNode* tmp = new circNode(val);
            tail->next = tmp;
            tmp->next = head;
            tmp->prev = tail;
            tail = tmp;
            head->prev = tail;
            size += 1;
        }
        return tail;
    }
    void pop() {
        if(size == 0) return;
        else if(size == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            size = 0;
        } else {
            circNode* h = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            h->next = NULL;
            h->prev = NULL;
            delete h;
            size -= 1;
        }
    }
    void erase(circNode* node) {
        if(node == tail) tail = tail->prev;
        else if(node == head) head = head->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = NULL;
        node->next = NULL;
        delete node;
    }
    int peek() {return head->val;}
    void next() {head = head->next; tail=tail->next;}
private:
    int size{0};
    circNode* head{NULL};
    circNode* tail{NULL};
};

class Solution {
public:
    string predictPartyVictory(string senate) {
        int size = senate.size();
        circList RList; circList DList; circList index;
        unordered_map<int, circNode*> imap;
        for(int i=0; i<size; i++) {
            imap[i] = index.push(i);
            if(senate[i] == 'R') RList.push(i);
            else DList.push(i);
        }
        while(!RList.empty() && !DList.empty()){
            int current = index.peek();
            if(current == RList.peek()) {
                index.erase(imap[DList.peek()]);
                DList.pop();
                RList.next();
            } else {
                index.erase(imap[RList.peek()]);
                RList.pop();
                DList.next();
            }
            index.next();
        }
        if(!RList.empty()) return "Radiant";
        else return "Dire";
        return "OK";
    }
};