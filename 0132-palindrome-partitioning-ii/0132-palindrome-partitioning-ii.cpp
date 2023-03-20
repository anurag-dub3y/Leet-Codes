class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    int minCut(string s) {
        int ans = 0;
        vector<int> dp(s.length(), INT_MAX);
        for (int i = 0; i < s.length(); i++) {
            if(isPalindrome(s, 0, i)){ dp[i] = 0; }
            else{ dp[i] = dp[i-1] + 1; }
            for (int j = i; j > 0; j--) {
                if(dp[i] == 1){ break; }
                if(isPalindrome(s, j, i)){ dp[i] = min(dp[i], dp[j-1] + 1); }
            }
        }
        return dp.back();
    }
};