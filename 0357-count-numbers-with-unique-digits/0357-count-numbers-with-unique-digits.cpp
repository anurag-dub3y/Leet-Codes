class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(10);
        dp[0]=1;
        dp[1]=10;
        for(int i=2; i<=9; i++){
            dp[i]=9;
            int k=9;
            for(int cnt=1; cnt<i; cnt++){
                dp[i]*=(k--);
            }
            dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};



