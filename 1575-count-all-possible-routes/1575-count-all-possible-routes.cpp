class Solution {
public:
    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        int mod=1e9+7;
        int dp[l.size()][fuel+1];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)> findWays=[&](int curr, int fuel){
            if(fuel<0){ return 0; }
            if(dp[curr][fuel]!=-1){ return dp[curr][fuel]; }
            int ans=0;
            if(curr==finish){ ans=1; }
            for(int i=0; i<l.size(); i++){
                if(i==curr){ continue; }
                ans=(1LL*ans+1LL*findWays(i,fuel-abs(l[i]-l[curr])))%mod;
            }
            return dp[curr][fuel]=ans;
        };
        return findWays(start,fuel);
    }
};