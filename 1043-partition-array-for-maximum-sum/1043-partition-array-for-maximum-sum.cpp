class Solution {
public:
    int dp[501][501];
    int find(int i, int j, int k, vector<int> &arr){
        if(j<i){ return 0; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        int currMax=0, len=1, ans=0;
        for(int r=i; r<=j and len<=k; r++, len++){
            currMax=max(currMax,arr[r]);
            int val=find(r+1,j,k,arr);
            ans=max(ans,currMax*len+val);
        }
        return dp[i][j]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,arr.size()-1,k,arr);
    }
};