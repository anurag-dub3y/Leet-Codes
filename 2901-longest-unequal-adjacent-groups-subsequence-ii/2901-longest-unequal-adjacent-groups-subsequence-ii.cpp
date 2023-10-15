class Solution {
public:
    int hammingDistance(const string& s1, const string& s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]){ count++; }
        }
        return count;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        unordered_map<int, vector<int>> lengthToIndex;
        for (int i = 0; i < n; i++) {
            lengthToIndex[words[i].length()].push_back(i);
        }
        vector<int> dp(n, 1), prev(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j : lengthToIndex[words[i].length()]) {
                if (j >= i) break;
                if (groups[i] != groups[j] && hammingDistance(words[i], words[j]) == 1) {
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
            }
        }
        int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<string> result;
        while (maxIndex != -1) {
            result.push_back(words[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};