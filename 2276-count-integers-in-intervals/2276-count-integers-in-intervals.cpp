class CountIntervals {
public:
    map<int,int> m;
    int ans=0;
    CountIntervals() { }
    void add(int left, int right) {
        auto it=m.upper_bound(left);
        if(it!=m.begin() and prev(it)->second>=left){ --it; }   // {{3,5}} {4,6} type case
        while(it!=m.end() and it->first<=right){    // Deleting overlapping intervals
            left=min(left,it->first);
            right=max(right,it->second);
            ans-=it->second-it->first+1;
            m.erase(it++);
        }
        m[left]=right;
        ans+=(right-left+1);
    }
    
    int count() {
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */