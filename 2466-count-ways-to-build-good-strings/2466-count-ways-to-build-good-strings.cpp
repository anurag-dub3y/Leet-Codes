class Solution {
public:
    int mod=1e9+7;
    int countGoodStrings(int low, int high, int x, int y) {
        vector<int> dp(high+1,0);
        dp[0]=1;
        int ans=0;
        for(int i=1; i<=high; i++){
            if(i>=x){ dp[i] = (dp[i] + dp[i - x]) % mod; }
            if(i>=y){ dp[i] = (dp[i] + dp[i - y]) % mod; }
            if(i>=low){ ans = (ans + dp[i]) % mod; }
        }
        return ans;
    }
};