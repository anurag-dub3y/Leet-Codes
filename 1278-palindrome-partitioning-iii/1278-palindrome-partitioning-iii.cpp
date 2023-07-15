class Solution {
public:
    int dp[101][101], C[101][101];
    const int inf = 1e2+5;
    int cost(string& s, int i, int j){
        if(i >= j) return 0;
        if(C[i][j] != -1) return C[i][j];
        return C[i][j] = (s[i] != s[j]) + cost(s, i+1, j-1);
    }
    int partition(string& s, int i, int k){
        if(k == 0) return cost(s, i, s.size()-1);
        if(i == s.size()) return inf;
        if(dp[i][k] != -1) return dp[i][k];
        int ans = inf;
        for(int part=i; part<s.size()-1; part++){
            ans = min(ans, cost(s, i, part) + partition(s, part+1, k-1));
        }
        return dp[i][k] = ans;
    }
    
    int palindromePartition(string s, int k) {
        memset(C, -1, sizeof(C));
        memset(dp, -1, sizeof(dp));
        return partition(s, 0, k-1);
    }
};