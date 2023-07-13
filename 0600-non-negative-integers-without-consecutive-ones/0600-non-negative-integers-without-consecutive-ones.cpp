class Solution {
public:
    int findIntegers(int num) {
        if(num < 3) return num + 1;
        vector<int> dp(32, 0);
        dp[0] = 2, dp[1] = 3;
        for(int i = 2; i < 32; i++){ 
            dp[i] = dp[i - 1] + dp[i - 2]; 
        }
        int hbit = 31;
        while((num & (1 << hbit)) == 0){ hbit--; }
        return (num & (1 << (hbit - 1))) ? dp[hbit] : dp[hbit - 1] + findIntegers(num ^ (1 << hbit));
    }
};