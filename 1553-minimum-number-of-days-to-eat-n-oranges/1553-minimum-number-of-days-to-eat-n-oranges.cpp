class Solution {
public:
    unordered_map<int,int> dp;
    int minDays(int n) {
        if(n<=1){ return n; }
        if(dp.count(n)==0){
            // If n is even, 
            // 1. If divisible by 2, eat n/2 else eat one and then eat n/2 on the next day
            // 2. If divisible by 3, eat 2*n/3 else eat one each day for n%3 days and 2*n/3 later, leaving you with n/3 oranges
            dp[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
        }
        return dp[n];
    }
};