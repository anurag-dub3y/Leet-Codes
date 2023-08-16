class Solution {
public:
    // unordered_map<int,int> dp;
    // int find(int i, vector<int> &nums, int k){
    //     if(i==nums.size()-1){ return nums.back(); }
    //     if(dp.count(i)){ return dp[i]; }
    //     int ans=-1e9;
    //     for(int j=i+1; j<=min(i+k,(int)nums.size()-1); j++){
    //         ans=max(ans,find(j,nums,k));
    //     }
    //     return dp[i]=nums[i]+ans;
    // }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        deque<int> dq={0};
        for(int i=1; i<n; i++){
            if(!dq.empty() and i-dq.front()>k){ dq.pop_front(); }
            dp[i]=nums[i]+dp[dq.front()];   // dq.front() has the max dp   
            while(!dq.empty() and dp[i]>=dp[dq.back()]){ dq.pop_back(); }
            dq.push_back(i);
        }
        return dp[dq.back()];
    }
};