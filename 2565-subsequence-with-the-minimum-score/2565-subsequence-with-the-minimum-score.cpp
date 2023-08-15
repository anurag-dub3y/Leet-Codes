class Solution {
public:
    int minimumScore(string s, string t) {
        vector<int> suffix(s.size(), -1); 
        int j = t.size()-1; 
        for (int i = s.size()-1; i >= 0; i--) {
            if (0 <= j && s[i] == t[j]) j--; 
            suffix[i] = j; 
        }
        int ans = j+1; 
        j = 0; 
        for (int i = 0; i < s.size(); i++) {
            ans = min(ans, max(0, suffix[i] - j + 1)); 
            if (j < t.size() && s[i] == t[j]) j++; 
        }
        return min(ans, (int) t.size()-j); 
    }
};