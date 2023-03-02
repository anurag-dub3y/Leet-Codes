class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {        
        dp.resize(size(strs), vector<vector<int> >(m + 1, vector<int>(n + 1)));
        return helper(strs, m, n, 0);
    }
    int helper(vector<string>& strs, int m, int n, int idx){
        if(idx == size(strs)) return 0; 
        if(dp[idx][m][n]) return dp[idx][m][n];
        int zeros = count(begin(strs[idx]), end(strs[idx]), '0'), ones = size(strs[idx]) - zeros;
        dp[idx][m][n] = helper(strs, m, n, idx + 1); 
        if(m - zeros >= 0 && n - ones >= 0){ 
            dp[idx][m][n] = max(dp[idx][m][n], 1 + helper(strs, m - zeros, n - ones, idx + 1));
        }
        return dp[idx][m][n]; 
    }
};