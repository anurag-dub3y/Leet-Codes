class Solution {
public:
    long long run(int i, vector<long long> &dp, vector<vector<int>>& q){
        if(i>=q.size()){ return 0; }
        if(dp[i]!=-1){ return dp[i]; }
        return dp[i]=max(run(i+1,dp,q),1LL*q[i][0]+run(i+q[i][1]+1,dp,q));
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long> dp(n+1,-1);
        run(0,dp,q);
        return *max_element(begin(dp),end(dp));
    }
};