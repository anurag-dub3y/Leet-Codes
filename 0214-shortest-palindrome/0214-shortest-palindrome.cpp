class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length(), pos=-1;
        long B = 29, MOD = 1000000007, POW = 1, hash1 = 0, hash2 = 0;
        for (int i = 0; i < n; i++, POW = POW * B % MOD) {
            hash1 = (hash1 * B + s[i] - 'a' + 1) % MOD;
            hash2 = (hash2 + (s[i] - 'a' + 1) * POW) % MOD;
            if(hash1 == hash2){ pos = i; }  // Means (0,pos) is a palindrome
        }
        string pref=s.substr(pos+1);
        reverse(begin(pref),end(pref));
        return pref+s;
    }
};