class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int k=coins.size();
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int j=0; j<k; j++){
            for(int i=1; i<=amount; i++){
                // if(i==coins[j]){ dp[i]+=1; }
                if(i>=coins[j]){ dp[i]+=dp[i-coins[j]]; }
            }
        }
        return dp[amount];
    }
};