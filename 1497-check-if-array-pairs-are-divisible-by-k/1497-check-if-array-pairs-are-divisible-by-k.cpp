class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto i:arr){ m[(i%k + k)%k]++; }
        for(auto it:m){ 
            if(it.first==0){ if(it.second%2){ return false; } }
            else if(m[k-it.first]!=it.second){ 
                return false; 
            } 
        }
        return true;
    }
};