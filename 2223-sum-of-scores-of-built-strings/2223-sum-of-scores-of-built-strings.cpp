class Solution {
public:
    #define ULL     unsigned long long
    #define LL      long long
    ULL hs = 3797;
    ULL F[100005], H[100005];
    
    ULL seg(int x, int y) {
        return H[y] - H[x - 1] * F[y - x + 1];
    }
    
    long long sumScores(string &s) {
        F[0] = 1; 
        for (int i = 1; i <= 100000; i++){ F[i] = F[i - 1] * hs; }
        for (int i = 1; i <= s.size(); i++){ H[i] = H[i - 1] * hs + s[i - 1]; }
        int n = s.size();
        LL ans = n;
        for (int i = 2; i <= n; i++) {
            int low = 0, high = (n - i + 1), reach = 0;
            while(low <= high) {
                int len = (low + high) >> 1;
                // Prefix of length len 
                // Equals a substring of length len, starting from i
                if (seg(1, 1 + len - 1) == seg(i, i + len - 1)) {
                    reach = len;
                    low = len + 1;
                } 
                else{ high = len - 1; }
            }
            ans += reach;
        }
        return ans;
    }
};