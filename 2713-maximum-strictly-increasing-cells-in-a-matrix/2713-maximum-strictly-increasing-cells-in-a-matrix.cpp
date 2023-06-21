class Solution {
public:
    map<pair<int,int>,int> dp;
    int dfs(int i, int j, vector<vector<int>>& mat){
        if(dp[{i,j}]){ return dp[{i,j}]; }
        // dp[{i,j}]=0;
        int ans=0;
        for(int r=0; r<mat.size(); r++){
            if(mat[r][j]>mat[i][j]){ 
                // cout<<mat[i][j]<<"->"<<mat[r][j]<<' ';
                if(dp[{r,j}]){ ans=max(ans,dp[{r,j}]); }
                else ans=max(ans,dfs(r,j,mat));
            }
            // else{ ans=max(ans,1+dp[{r,j}]); }
        }
        for(int c=0; c<mat[0].size(); c++){
            if(mat[i][c]>mat[i][j]){ 
                // cout<<mat[i][j]<<"->"<<mat[i][c]<<' ';
                if(dp[{i,c}]){ ans=max(ans,dp[{i,c}]); }
                else ans=max(ans,dfs(i,c,mat)); 
            }
            // else{ ans=max(ans,1+dp[{i,c}]); }
        }
        // cout<<i<<','<<j<<' ';
        // cout<<1+ans<<"  ";
        return dp[{i,j}]=1+ans;
    }
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> rowMx(m,0), colMx(n,0);
        set<int,greater<int>> vals;
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]].push_back({i,j});
                vals.insert(mat[i][j]);
            }
        }
        int ans=0;
        for(auto m:vals){
            for(auto &[i,j]:mp[m]){
                dp[{i,j}]=max(rowMx[i],colMx[j])+1;
                ans=max(ans,dp[{i,j}]);
            }
            for(auto &[i,j]:mp[m]){
                rowMx[i]=max(rowMx[i],dp[{i,j}]);
                colMx[j]=max(colMx[j],dp[{i,j}]);
            }
        }
        return ans;
    }
};


