class Solution {
public:
    int dfs(vector<int> &slices, int i,int end, int remaining, vector<vector<int>> &dp)     {
        if(i>end || remaining==0) return 0;
        int &ans=dp[i][remaining];
        if(ans!=-1) return ans;
        ans=dfs(slices,i+1,end,remaining,dp);
        return ans=max(slices[i]+dfs(slices, i+2, end, remaining-1, dp), ans);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        vector<vector<int>> dp(slices.size(), vector<int> (slices.size()/3+1, -1));    
        int ans1=dfs(slices,0, slices.size()-2,slices.size()/3, dp);
        dp=vector<vector<int>> (slices.size(), vector<int> (slices.size()/3+1, -1));
        int ans2=dfs(slices,1, slices.size()-1,slices.size()/3, dp);
        return max(ans1, ans2);
    }
};