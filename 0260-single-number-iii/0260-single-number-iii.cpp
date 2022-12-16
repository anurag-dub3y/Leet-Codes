class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> u;
        for(auto i:nums){ u[i]++; }
        long long a=3e9, b=3e9;
        for(auto it:u){
            if(it.second==1 and a==3e9){ a=it.first; }
            else if(it.second==1 and a!=3e9){ b=it.first; }
        }
        return {(int)a,(int)b};
    }
};