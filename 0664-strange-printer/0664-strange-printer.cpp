class Solution {
public:
    int dp[101][101], n;
    int find(int left, int right, string &s) {
        
        int &val= dp[left][right];
        if (val != -1) { return val; }
        
        val = n;
        int j = -1;
        
        for (int i = left; i < right; i++) {
            if (s[i] != s[right] && j == -1) {
                j = i;
            }
            
            if (j != -1) { val = min(val, 1 + find(j, i, s) + find(i + 1, right, s)); }
        }
            
        if (j == -1) { val = 0; }
        
        return val;
    };
    int strangePrinter(string &s) {
        this -> n = s.size();
        memset(dp,-1,sizeof(dp));
        return find(0, n - 1, s) + 1;
    }
};