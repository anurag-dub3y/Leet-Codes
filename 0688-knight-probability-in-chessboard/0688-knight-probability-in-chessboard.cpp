class Solution {
public:
    int N;
    double dp[26][26][101];
    int moves[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    bool isValid(int i, int j){ return min(i,j)>=0 and max(i,j)<N; }
    double dfs(int i, int j, int k){
        if(!isValid(i,j)){ return 0; }
        if(k==0){ return 1.0; }
        if(dp[i][j][k]!=0){ return dp[i][j][k]; }
        double chance=0.0;
        for(int r=0; r<8; r++){
            int newI=i+moves[r][0], newJ=j+moves[r][1];
            chance+=0.125*dfs(newI,newJ,k-1);
        }
        return dp[i][j][k]=chance;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        N=n;
        return dfs(row,column,k);
    }
};