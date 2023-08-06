class Solution {
public:
    int n, m;
    int dp[101][101];
    bool check(int i, int j, vector<int> &pre){
        if(j-i==1){ return true; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        int &val=dp[i][j];
        val=0;
        if(pre[j]-pre[i]>=m){ val=val|check(i,j-1,pre); }
        if(pre[j+1]-pre[i+1]>=m){ val=val|check(i+1,j,pre); }
        return val;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        this->n=nums.size(); this->m=m;
        if(n<3){ return true; }
        vector<int> pre={0};
        for(auto &k:nums){ pre.push_back(pre.back()+k); }
        memset(dp,-1,sizeof(dp));
        return check(0,n-1,pre);
    }
};