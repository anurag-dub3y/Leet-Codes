class Solution {
public:
    // map<pair<int,int>,int> dp;
    // int minJ(int row, int pos, vector<int>& obs){
    //     if(pos==obs.size()){ return 0; }
    //     if(dp.count({pos,row})){ return dp[{pos,row}]; }
    //     int ans=1e9;
    //     if(obs[pos+1]==row+1){
    //         if(row==0){
    //             if(obs[pos]!=2){ ans=min(ans,1+minJ(1,pos,obs)); }
    //             if(obs[pos]!=3){ ans=min(ans,1+minJ(2,pos,obs)); }
    //         }
    //         if(row==1){
    //             if(obs[pos]!=1){ ans=min(ans,1+minJ(0,pos,obs)); }
    //             if(obs[pos]!=3){ ans=min(ans,1+minJ(2,pos,obs)); }
    //         }
    //         if(row==2){
    //             if(obs[pos]!=1){ ans=min(ans,1+minJ(0,pos,obs)); }
    //             if(obs[pos]!=2){ ans=min(ans,1+minJ(1,pos,obs)); }
    //         }
    //     }
    //     else{
    //         ans=minJ(row,pos+1,obs);
    //     }
    //     return dp[{pos,row}]=ans;
    // }
    // int minSideJumps(vector<int>& obstacles) {
    //     // memset(dp,-1,sizeof(dp));
    //     return minJ(1,0,obstacles);
    // }
    int find(vector<int>& obstacles, int pos,int currlane,vector<vector<int>>& dp){
        if(pos==obstacles.size()-1){ return 0; }
        if(dp[currlane][pos]!=-1) return dp[currlane][pos];
        if(currlane!=obstacles[pos+1]){
            return find(obstacles,pos+1,currlane,dp);
        }
        else{
            int ans=1e9;
            for(int i=1; i<=3; i++){
                if(currlane!=i and obstacles[pos]!=i)
                ans=min(ans,1+find(obstacles,pos+1,i,dp));
            }
            return dp[currlane][pos]=ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {  
        vector<vector<int>> dp(4, vector<int>(obstacles.size(),-1));
        return find(obstacles,0,2,dp);
        
    }
};
