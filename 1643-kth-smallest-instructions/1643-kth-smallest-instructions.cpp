class Solution {
public:
    int dp[16][16];
    int dfs(int i, int j, int d1, int d2){
        if(i>d1 or j>d2){ return 0; }
        if(i==d1 and j==d2){ return dp[d1][d2]=1; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        return dp[i][j]=dfs(i,j+1,d1,d2)+dfs(i+1,j,d1,d2);
    }
    string kthSmallestPath(vector<int>& d, int k) {
        memset(dp,-1,sizeof(dp));
        dfs(0,0,d[0],d[1]);
        // for(int i=0; i<=d[0]; i++){
        //     for(int j=0; j<=d[1]; j++){ cout<<dp[i][j]<<' '; }
        //     cout<<endl;
        // }
        int i=0, j=0, d1=d[0], d2=d[1];
        string curr="";
        while (i < d1 && j < d2) {
            if (k <= dp[i][j + 1]) {
                curr += 'H';
                j++;
            } else {
                k -= dp[i][j + 1];
                curr += 'V';
                i++;
            }
        }
        
        while (i < d1) {
            curr += 'V';
            i++;
        }
        
        while (j < d2) {
            curr += 'H';
            j++;
        }
        
        return curr;
    }
};