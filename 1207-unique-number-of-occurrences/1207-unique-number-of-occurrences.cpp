class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> u;
        unordered_map<int,int> k;
        for(auto i:arr){ ++k[i]; }
        for(auto i:k){
            int z=i.second;
            if(u.count(z)!=0){ return false; }
            u.insert(z);
        }
        return true;
    }
};