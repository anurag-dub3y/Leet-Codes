int dp[21][21][2];
class Solution {
public:
    // Chance 0 is for Player 1
    int find(int i, int j, int chance, vector<int>& nums){
        if(i==j){ return nums[i]; }
        if(dp[i][j][chance]!=-1){ return dp[i][j][chance]; }
        int &val=dp[i][j][chance];
        if(chance==0){
            return val=max(nums[i]+find(i+1,j,!chance,nums),nums[j]+find(i,j-1,!chance,nums));
        }
        else{
            return val=min(-nums[i]+find(i+1,j,!chance,nums),-nums[j]+find(i,j-1,!chance,nums));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(0,n-1,0,nums)>=0;
    }
};