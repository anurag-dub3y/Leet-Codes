class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        int dp[n];
        deque<int> dq;
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(!dq.empty() and i-dq.front()>k){ dq.pop_front(); }
            int mx=0;
            if(!dq.empty()){ mx=max(mx,dp[dq.front()]); }
            while(!dq.empty() and nums[i]+mx>=dp[dq.back()]){
                dq.pop_back();
            }
            dp[i]=nums[i]+mx;
            dq.push_back(i);
            ans=max(ans,dp[dq.back()]);
        }
        return ans;
    }
};