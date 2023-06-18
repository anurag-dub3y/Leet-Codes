class Solution {
public:
    int dp[1003][1003]={0};
    int dir[5]={-1,0,1,0,-1};
    int mod=1e9+7;
    bool isValid(int i, int j, vector<vector<int>> &g){
        return !(i<0 or j<0 or i>=g.size() or j>=g[0].size());
    }
    int dfs(int i, int j, vector<vector<int>>& g){
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int val=1;
        for(int k=1; k<5; k++){
            int newJ=j+dir[k], newI=i+dir[k-1];
            if(isValid(newI,newJ,g) && g[i][j]<g[newI][newJ]){
                int k=dfs(newI,newJ,g);
                (val+=k)%=mod;
            }
        }
        return dp[i][j]=val;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                (ans+=dfs(i,j,grid))%=mod; 
            }
        }
        return ans;
    }
};