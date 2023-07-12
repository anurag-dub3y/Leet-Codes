class Solution {
public:
    using ll=long long;
    ll mod=1e9+7;
    ll dp[1001][1001];
    ll findWays(int i, vector<int>& nums, ll curr, int k){
        if(curr>=k){ return 0; }
        if(i==nums.size()){ return 1; }
        if(dp[i][curr]!=-1){ return dp[i][curr]; }
        ll ans=0;
        // Either nums[i] is in the subset or it is not in it
        ans=(1LL*findWays(i+1,nums,curr,k)+findWays(i+1,nums,curr+nums[i],k))%mod;
        return dp[i][curr]=ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        ll sum=accumulate(begin(nums),end(nums),0LL);
        if(sum<2*k){ return 0; }
        memset(dp,-1,sizeof(dp));
        ll total=1LL;
        for(int i=0; i<nums.size(); i++){
            total=(2LL*total)%mod;
        }
        return (1LL*total+mod-2LL*findWays(0,nums,0,k))%mod;
    }
};