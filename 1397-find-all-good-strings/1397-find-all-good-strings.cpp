class Solution {
public:
    int sz, n, mod = 1e9 + 7;
    int dp[501][51][2][2];
    vector<int> pre;

    int find(int i, int subLen, bool x, bool y, string &s1, string &s2, string &evil) {
        if (subLen == sz) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (dp[i][subLen][x][y] != 0) {
            return dp[i][subLen][x][y];
        }
        long ans = 0;
        char start = x ? s1[i] : 'a';
        char end = y ? s2[i] : 'z';
        for (char c = start; c <= end; c++) {
            int j = subLen;
            while (j > 0 and evil[j] != c) {
                j = pre[j - 1];
            }
            if (c == evil[j]) {
                j++;
            }
            ans = (ans + find(i + 1, j, x && c == s1[i], y && c == s2[i], s1, s2, evil)) % mod;
        }
        dp[i][subLen][x][y] = ans;
        return dp[i][subLen][x][y];
    }

    int findGoodStrings(int N, string s1, string s2, string evil) {
        sz = evil.length();
        n = N;
        pre = vector<int>(sz, 0);
        for (int i = 1, j = 0; i < sz; i++) {
            while (j > 0 && evil[i] != evil[j]) {
                j = pre[j - 1];
            }
            if (evil[i] == evil[j]) {
                j++;
            }
            pre[i] = j;
        }
        memset(dp, 0, sizeof(dp)); // Initialize dp array with zeros
        return find(0, 0, 1, 1, s1, s2, evil);
    }
};
