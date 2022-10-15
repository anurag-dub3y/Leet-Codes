class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        for(auto i:nums){ sum+=i; ans=min(sum,ans); }
        return ans>=1?1:1+abs(ans);
    }
};