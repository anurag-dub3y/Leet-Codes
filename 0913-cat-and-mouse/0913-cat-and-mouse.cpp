class Solution {
public:
    // int vis[51][51];
    int dp[51][51][255], n;
    int find(int i, int j, int move, vector<vector<int>>& graph){
        // move%2?cout<<i<<' '<<j<<' '<<"cat"<<endl:cout<<i<<' '<<j<<' '<<"mouse"<<endl;
        if(move>250){ return 0; }
        if(i==j){ return dp[i][j][move]=2; }
        else if(i==0){ return dp[i][j][move]=1; }
        // if(vis[i][j]!=0){ return 0; }
        if(dp[i][j][move]!=-1){ return dp[i][j][move]; }
        // vis[i][j]=1;
        int ans;
        if(move%2==0){  // Mouse moves
            ans=2;      // Worst case, cat wins
            for(auto k:graph[i]){
                int nextMove=find(k,j,move+1,graph);
                if(nextMove==1){ ans=1; break; }    // Best case, mouse wins
                else if(nextMove==0){ ans=0; }                      // Mid case, insurance
            }
        }
        else{           // Cat moves
            ans=1;      // Worst case, mouse wins
            for(auto k:graph[j]){
                if(k==0){ continue; }
                int nextMove=find(i,k,move+1,graph);
                if(nextMove==2){ ans=2; break; }    // Best case, cat wins
                else if(nextMove==0){ ans=0; }                      // Mid case, insurance
            }
        }
        return dp[i][j][move]=ans;
    }
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        // cout<<endl;
        n=graph.size();
        return find(1,2,0,graph);  
    }
};