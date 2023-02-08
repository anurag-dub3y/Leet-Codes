class Solution {
public:
    int n;
    int dp[1001][51];
    int find(int i, int k, vector<int>& nums){
        if(k<0){ return 1e9; }
        if(i==nums.size()){
            if(k==0){ return 0; }
            return 1e9;
        }
        if(dp[i][k]!=-1){ return dp[i][k]; }
        int ans=1e9, sum=0;
        for(int j=i; j<n; j++){
            sum+=nums[j];
            ans=min(ans,max(sum,find(j+1,k-1,nums)));
        }
        return dp[i][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(0,k,nums);
    }
};