long long dp[101][10202];
class Solution {
public:
    long long find(int i, int j, vector<int>& r, vector<int>& f){
        if(i>=r.size()){ return 0LL; }
        if(j==f.size()){ return 1e12; }
        if(dp[i][j]!=-1LL){ return dp[i][j]; }
        
        long long ans=find(i,j+1,r,f);
        ans=min(ans,abs(r[i]-f[j])+find(i+1,j+1,r,f));

        return dp[i][j]=ans;
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(begin(r),end(r));
        sort(begin(f),end(f));
        vector<int> pos;
        for(auto &it:f){
            for(int i=0; i<it[1]; i++){ pos.push_back(it[0]); }
        }
        memset(dp,-1LL,sizeof(dp));
        return find(0,0,r,pos);
    }
};