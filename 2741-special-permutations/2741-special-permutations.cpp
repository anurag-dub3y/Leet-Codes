class Solution {
public:
    // int dp[15][1<<15];
    // int find(int lastInd, vector<int> &nums, int bitMask){
    //     if(bitMask==(1<<nums.size()-1)){ return 1; }
    //     if(dp[lastInd][bitMask]==-1){
    //         dp[lastInd][bitMask]=0;
    //         for(int i=0; i<nums.size(); i++){
    //             if((bitMask&(1<<i))==0 and (bitMask==0 or nums[i]%nums[lastInd]==0 or nums[lastInd]%nums[i]==0)){
    //                 dp[lastInd][bitMask]=(dp[lastInd][bitMask]+find(i,nums,bitMask+(1<<i)))%1000000007;
    //             }
    //         }
    //     }
    //     return dp[lastInd][bitMask];
    // }
    int dp[14][16383];
    // int dfs(int i, int mask, vector<int>& nums) {
    //     if (mask == (1 << nums.size()) - 1)
    //         return 1;
    //     if (dp[i][mask] == -1) {
    //         dp[i][mask] = 0;
    //         for (int j = 0; j < nums.size(); ++j) {
    //             if ((mask & (1 << j)) == 0 && (mask == 0 || nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
    //                 dp[i][mask] = (dp[i][mask] + dfs(j, mask + (1 << j), nums)) % 1000000007;
    //             }
    //         }
    //     }
    //     return dp[i][mask];
    // }
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        function<int(int,int)> dfs = [&](int i, int mask){
            if (mask == (1 << nums.size()) - 1) return 1;
            if (dp[i][mask] == -1) {
                dp[i][mask] = 0;
                for (int j = 0; j < nums.size(); ++j) {
                    if ((mask & (1 << j)) == 0 && (mask == 0 || nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
                        dp[i][mask] = (dp[i][mask] + dfs(j, mask + (1 << j))) % 1000000007;
                    }
                }
            }
            return dp[i][mask];
        };
        return dfs(0, 0);
    }
};