class Solution {
public:
    int n;
    int dp[101][101];
    int find(int i, int k, vector<int> &h){
        // if(k>i+1){ return 1e9; }
        if(k>=i+1){ return 0; }
        if(k==0){ return 1e9; }
        int &ans=dp[i][k];
        if(ans!=-1){ return ans; }
        ans=1e9;
        for(int j=i; j>=0; j--){
            int mid=h[(i+j)/2];
            int currDiff=0;
            for(int r=j; r<=i; r++){ currDiff+=abs(mid-h[r]); }
            ans=min(ans,currDiff+find(j-1,k-1,h));
        }
        return ans;
    }
    int minDistance(vector<int>& h, int k) {
        this->n=h.size();
        sort(begin(h),end(h));
        memset(dp,-1,sizeof(dp));
        return find(n-1,k,h);
    }
};