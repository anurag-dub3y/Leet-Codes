class Solution {
public:
    int memo[41][1025];
    int mod=1e9+7;
    int n;
    unordered_map<int,vector<int>> persons;
    long long dp(int hat,int mask){
        if(hat==41){
            if(mask==((1<<n)-1)) return 1;
            return 0;
        }
        if(memo[hat][mask]!=-1){ return memo[hat][mask]; }
        int ans=0;
        for(int p:persons[hat]){
            if((mask&(1<<p))==0) {
                ans+=dp(hat+1,mask|(1<<p));
                ans%=mod;
            }
        }
        //dont take any person
        ans+=dp(hat+1,mask);
        return memo[hat][mask]=ans%mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        n=hats.size();
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            vector<int> L=hats[i];
            for(int h:L){
                persons[h].push_back(i);
            }
        }
        return dp(1,0);
    }
};