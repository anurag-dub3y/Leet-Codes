class RandomizedCollection {
public:
    map<int,vector<int>> mp;
    vector<pair<int,int>> vp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=mp.count(val);
        mp[val].push_back(vp.size());
        vp.push_back({val,mp[val].size()-1});
        return !ans;
    }
    
    bool remove(int val) {
        auto it=mp.find(val);
        if(it!=mp.end()){
            // Swap latest val in the nums array with the latest insert entry 
            int lastVal=vp.back().first, lastInd=vp.back().second;
            mp[lastVal][lastInd]=mp[val].back();
            vp[mp[val].back()]=vp.back();
            vp.pop_back();
            mp[val].pop_back();
            if(mp[val].size()==0){ mp.erase(val); }
        }
        return it!=mp.end();
    }
    
    int getRandom() {
        return vp[rand()%vp.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */