class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int val) {
        if(mp.count(val)==0){ return 0; }
        // for(auto i:mp[val]){ cout<<i<<' '; }
        // cout<<endl;
        int r=(upper_bound(begin(mp[val]),end(mp[val]),right)-lower_bound(begin(mp[val]),end(mp[val]),left));
        // cout<<r<<endl;
        return r;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */