class StockPrice {
public:
    map<int,int> m;
    multiset<int> ms;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m.find(timestamp)!=m.end()){
            ms.erase(ms.find(m[timestamp]));
        }
        m[timestamp]=price;
        ms.insert(price);
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */