class Solution {
public:
    int mod=1e9+7;
    int dp[101][201];
    int findWays(vector<int>& l, int curr, int finish, int fuel){
        if(fuel<0){ return 0; }
        if(dp[curr][fuel]!=-1){ return dp[curr][fuel]; }
        int ans=0;
        if(curr==finish){ ans=1; }
        for(int i=0; i<l.size(); i++){
            if(i==curr){ continue; }
            ans=(1LL*ans+1LL*findWays(l,i,finish,fuel-abs(l[i]-l[curr])))%mod;
        }
        return dp[curr][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return findWays(locations,start,finish,fuel);
    }
};