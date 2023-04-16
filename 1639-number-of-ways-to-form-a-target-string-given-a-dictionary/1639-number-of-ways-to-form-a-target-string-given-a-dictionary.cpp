class Solution {
public:
    int numWays(vector<string>& w, string t) {
        int mod = 1e9+7, m=w.size(), l=w[0].length(), n=t.length();
        if(l<n){ return 0; }
        vector<vector<int>> cnt(l, vector<int>(26,0));
        for(int i=0; i<l; i++){
            for(int j=0; j<m; j++){ 
                cnt[i][w[j][i] - 'a']++; 
                // sum of frequency of chars at ith index for all w[j]
            }
        }
        vector<vector<int>> dp(l+1, vector<int>(n+1));
        // dp[i][j] = Num of ways to match t[0,j] using cnt[0,i]
        for(int i=0; i<l; i++) {
            dp[i][0] = 1;
            for(int j=0; j<=i and j<n; j++){
                dp[i+1][j+1] = ((1LL*cnt[i][t[j]-'a'] * dp[i][j]) % mod + 1LL*dp[i][j+1]) % mod;
            }
        }
        return dp[l][n];
    }
};

// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/discuss/917672/C%2B%2B-DP-bottom-up-with-explanation