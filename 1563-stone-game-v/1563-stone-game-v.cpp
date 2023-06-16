class Solution {
public:
    int dp[505][505];
    int find(int i, int j, vector<int> &pre){
        if(i==j){ return 0; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        int ans=0;
        for(int k=i+1; k<=j; k++){
            int lSum=pre[k]-pre[i], rSum=pre[j+1]-pre[k];
            if(lSum<rSum){
                ans=max(ans,lSum+find(i,k-1,pre));
            }
            else if(lSum>rSum){
                ans=max(ans,rSum+find(k,j,pre));
            }
            else{
                ans=max(ans,lSum+max(find(i,k-1,pre),find(k,j,pre)));
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stone) {
        vector<int> pre={0};
        for(auto i:stone){ pre.push_back(pre.back()+i); }
        memset(dp,-1,sizeof(dp));
        return find(0,stone.size()-1,pre);
    }
};