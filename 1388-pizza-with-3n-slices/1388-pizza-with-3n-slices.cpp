class Solution {
public:
    int maxSizeSlices(vector<int>& slices, int l, int r){
        int N = slices.size();
        int k = N/3; 
        vector<vector<int>> dp(N, vector<int>(k, 0));
        for(int i = l; i <= r; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = max((i-1 >= 0 ? dp[i-1][j] : 0), 
                               (((i-2 >= 0) && (j-1 >= 0)) ? dp[i-2][j-1] : 0) + slices[i]);
            }
        }
        return dp[r][k-1];
    };
    
    int maxSizeSlices(vector<int>& slices) {
        int N = slices.size();
        return max(maxSizeSlices(slices, 0, N-2), maxSizeSlices(slices, 1, N-1));
    }
};