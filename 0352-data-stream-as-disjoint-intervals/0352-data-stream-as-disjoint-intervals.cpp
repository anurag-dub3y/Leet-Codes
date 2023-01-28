class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        auto it=st.begin();
        while(it!=st.end()){
            int start=*it, end=start;
            while(it!=st.end() and next(it)!=st.end() and *next(it)==*it+1){
                end=*next(it);
                it=next(it);
            }
            ans.push_back({start,end});
            it=next(it);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */