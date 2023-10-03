class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> u;
        int ans=0;
        for(auto &i:nums){
            ans+=u[i];
            u[i]++;
        }
        return ans;
    }
};