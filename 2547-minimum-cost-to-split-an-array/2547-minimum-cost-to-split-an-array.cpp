class Solution {
public:
    int trimmed[1003][1003], dp[1003], n;
    int dfs(vector<int>& nums, int i, int k){
        if(i>=nums.size()){ return 0; }
        if(dp[i]!=-1){ return dp[i]; }
        int ans=INT_MAX;
        for(int j=i; j<n; j++){
            int left=k+trimmed[i][j];
            int right=dfs(nums,j+1,k);
            ans=min(ans,left+right);
        }
        return dp[i]=ans;
    }
    int minCost(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++){
            unordered_map<int,int> u;
            int count=0;
            for(int j=i; j<n; j++){
                if(u.find(nums[j])!=u.end()){
                    if(u[nums[j]]==1){ count+=2; }
                    else{ count++; }
                }
                ++u[nums[j]];
                trimmed[i][j]=count;
            }
        }
        return dfs(nums,0,k);
    }
};