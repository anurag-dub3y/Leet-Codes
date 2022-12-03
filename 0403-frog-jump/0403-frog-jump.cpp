class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        // dp[i][j] means you can get to ith stone after jumping from [i-j]th stone (thus having jumpDist=j)
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        dp[0][1]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int jumpDist=stones[i]-stones[j];
                if(jumpDist>n or dp[j][jumpDist]==0){ continue; }
                else if(i==n-1){ return true; }
                dp[i][jumpDist]=1;
                // We could have got here with a jump of jumpDist-1 or jumpDist+1 length as well 
                if(jumpDist-1>=0){ dp[i][jumpDist-1]=1; }   
                if(jumpDist+1>=0){ dp[i][jumpDist+1]=1; }
            }
        }
        return false;
    }
};