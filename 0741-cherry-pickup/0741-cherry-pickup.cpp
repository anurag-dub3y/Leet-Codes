class Solution {
public:
    int n;
    int dp[51][51][51][51];
    int search(int r1, int c1, int r2, int c2, vector<vector<int>>& grid){
        if(min({r1,c1,r2,c2})<0 or max({r1,c1,r2,c2})>=n or min(grid[r1][c1],grid[r2][c2])==-1){ return INT_MIN; }
        if(r1==n-1 and c1==n-1){ return grid[n-1][n-1]; }
        if(dp[r1][c1][r2][c2]!=0){
            return dp[r1][c1][r2][c2];
        }
        int cherries=0;
        if(r1==r2 and c1==c2){ cherries+=grid[r1][c1]; }
        else{ cherries+=(grid[r1][c1]+grid[r2][c2]); }
        int v1=search(r1+1,c1,r2+1,c2,grid);
        int v2=search(r1+1,c1,r2,c2+1,grid);
        int v3=search(r1,c1+1,r2+1,c2,grid);
        int v4=search(r1,c1+1,r2,c2+1,grid);
        cherries+=max({v1,v2,v3,v4});
        return dp[r1][c1][r2][c2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,0,sizeof(dp));
        return max(search(0,0,0,0,grid),0);
    }
};