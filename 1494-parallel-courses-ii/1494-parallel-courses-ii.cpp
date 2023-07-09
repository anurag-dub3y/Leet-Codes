int dp[1<<16];
class Solution {
public:
    int MASK;
    int find(int mask, int n, map<int,vector<int>> &reqd, int k){
        if(mask==MASK){ return 0; }
        if(dp[mask]!=-1){ return dp[mask]; }
        int temp=0;
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){ continue; }
            int take=1;
            for(auto j:reqd[i]){
                if((mask&(1<<j))==0){ take=0; break; }
            }
            if(take){ temp|=(1<<i); }
        }
        int j=temp;
        int cnt=__builtin_popcount(j);  
        int ans=n+1;  // ans will be 'n' in the worst case, so take (n+1) as infinity 
        if(cnt>k) {
            for( ; j ; j=(j-1)&temp )  // iterate through all submasks of temp
            {
                cnt=__builtin_popcount(j);  
                if(cnt!=k){ continue; }
                ans=min(ans,1+find(mask|j,n,reqd,k));                   
            }
        }
        else { ans=min(ans,1+find(mask|j,n,reqd,k)); }
        return dp[mask]=ans;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        memset(dp,-1,sizeof(dp));        
        MASK=(1<<n)-1;
        map<int,vector<int>> reqd;
        for(auto r:relations){ reqd[r[1]-1].push_back(r[0]-1); }
        return find(0,n,reqd,k);
    }
};