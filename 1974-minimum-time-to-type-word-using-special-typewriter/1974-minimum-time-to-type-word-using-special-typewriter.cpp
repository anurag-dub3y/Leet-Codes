class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.length(), last = 'a';
        for (auto c : word) {
            ans += min(abs(c - last), 26 - abs(last - c));
            last = c;
        }
        return ans;
    }
};