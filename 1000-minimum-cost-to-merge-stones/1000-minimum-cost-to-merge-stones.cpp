class Solution {
public:
    vector<int> pre;
    int n;
    int dp[31][31];
    int find(int i, int j, int k){
        if(i>=j){ return 0; }
        if(i+k-1==j){ 
            // cout<<i<<' '<<j<<' '<<pre[j+1]-pre[i]<<endl;
            return dp[i][j]=pre[j+1]-pre[i]; 
        }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        long long ans=INT_MAX;
        for(int ind=i; ind<j; ind+=(k-1)){
            long long cost = 1LL*find(i,ind,k) + find(ind+1,j,k);
            ans=min(cost,ans);
        }
        if((j-i)%(k-1)==0){ ans=ans+pre[j+1]-pre[i]; }
        // cout<<i<<' '<<j<<' '<<ans<<endl;
        return dp[i][j]=ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        pre.push_back(0);
        n=stones.size();
        if((n-1)%(k-1)!=0){ return -1; }
        for(auto s:stones){ pre.push_back(s+pre.back()); }
        memset(dp,-1,sizeof(dp));
        return find(0,n-1,k);
    }
};
