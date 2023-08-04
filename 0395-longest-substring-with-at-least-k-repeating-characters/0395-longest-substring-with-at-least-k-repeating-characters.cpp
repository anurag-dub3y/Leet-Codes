class Solution {
public:
    map<string,int> dp;
    int longestSubstring(string &s, int k) {
        int n = (int)s.length();
        if(dp.count(s)){ return dp[s]; }
        unordered_map<char, int> count;
        for(auto &c : s){ ++count[c]; }
        int mid = 0;
        while(mid < n && count[s[mid]] >= k){ mid++; }
        if(mid==n){ return n; }
        string leftTmp=s.substr(0,mid); 
        int left = longestSubstring(leftTmp, k);
        while(mid < n && count[s[mid]] < k){ ++mid; }
        string rightTmp=s.substr(mid);
        int right = longestSubstring(rightTmp, k);
        return max(left, right);
    }
};