class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int u[101]={};
        int ans=0;
        for(auto &i:nums){
            ans+=u[i];
            u[i]++;
        }
        return ans;
    }
};