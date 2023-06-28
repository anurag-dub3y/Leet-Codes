class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        for(auto &cube: c){ sort(cube.begin(), cube.end()); }
        sort(c.begin(), c.end());
        int ans = 0, n = c.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(c[j][0] <= c[i][0] && c[j][1] <= c[i][1] && c[j][2] <= c[i][2]){
                    dp[i] = max(dp[i], dp[j]);
                    // Placing ith cuboid on top of jth cuboid
                }
            }
            dp[i] += c[i][2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};