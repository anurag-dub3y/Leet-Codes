class Solution {
public:
    int dp[10004][101];
    int find(int k, int n){
        if(n<=1){ return n; }
        else if(k==1){ return n; }
        if(dp[n][k]!=-1){ return dp[n][k]; }
        int low=0, high=n, ans=1e9, val=0;
        while(low<=high){
            // dropping from middle floor
            int mid=low+(high-low)/2;
            int breaks=find(k-1,mid-1), notBreaks=find(k,n-mid);
            val=1+max(breaks,notBreaks);
            if(breaks>notBreaks){ high=mid-1; }
            else{ low=mid+1; }
            ans=min(ans,val);
        }
        return dp[n][k]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return find(k,n);
    }
    int twoEggDrop(int n) {
        return superEggDrop(2,n);
    }
};