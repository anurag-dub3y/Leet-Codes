class Solution {
public:
    int dp[1001][2002];
    int n, k;
    int search(int i, int k, vector<vector<int>>& piles){
        if(i>=n or k<=0){ return 0; }
        if(dp[i][k]!=-1){ return dp[i][k]; }
        int ans=0;
        ans=max(ans,search(i+1,k,piles));
        int sum=0;
        for(int j=0; j<piles[i].size() and j<k; j++){
            sum+=piles[i][j];
            ans=max(ans,sum+search(i+1,k-j-1,piles));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int choice) {
        n=piles.size(), k=choice;
        memset(dp,-1,sizeof(dp));
        return search(0,k,piles);
    }
};