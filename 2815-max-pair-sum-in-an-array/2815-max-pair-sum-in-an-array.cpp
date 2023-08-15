class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<char,vector<int>> m;
        for(auto &i:nums){
            string s=to_string(i);
            sort(begin(s),end(s));
            m[s.back()].push_back(i); 
        }
        int ans=-1;
        for(auto &[ch,it]:m){
            if(it.size()<2){ continue; }
            sort(begin(it),end(it),greater<int>());
            ans=max(ans,it[0]+it[1]);
        }
        return ans;
    }
};