class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, int> charMap;
        unordered_map<char, bool> firstChars;
        for (auto &word : words) {
            int base = 1;
            for (int i = word.length() - 1; i >= 0; i--) {
                charMap[word[i]] += base;
                base *= 10;
            }    
            if (word.length() > 1) firstChars[word[0]] = true;
        }
        int base = 1;
        for (int i = result.length() - 1; i >= 0; i--) {
            charMap[result[i]] -= base;
            base *= 10;
        }
        if (result.length() > 1) firstChars[result[0]] = true;
        vector<int> chars(charMap.size());
        int nonZeroInds = 0;
        int zeroInds = charMap.size() - 1;
        for (auto &p : charMap) {
            if (firstChars[p.first]) chars[nonZeroInds++] = p.second;
            else chars[zeroInds--] = p.second;
        }
        sort(chars.begin(), chars.begin() + nonZeroInds);
        sort(chars.begin() + nonZeroInds, chars.end());
        vector<int> sums = vector<int>(1, 0);
        for (int i = chars.size() - 1; i >= 0; i--) sums.push_back(abs(chars[i])*9 + sums.back());
        reverse(sums.begin(), sums.end());
        return dfs(chars, nonZeroInds, 0, 0, 0, sums);
    }
    
    bool dfs(vector<int> &chars, int zeroInd, int ind, int used, int curSum, vector<int>& sums) {
        if (ind == chars.size()) return curSum == 0;
        else if (abs(curSum) > sums[ind]) return false;
        for (int i = 0; i < 10; i++) {
            if (((used >> i) & 1) == 1 || (i == 0 && ind < zeroInd)) continue;
            if (dfs(chars, zeroInd, ind + 1, used | (1 << i), curSum + chars[ind]*i, sums)) return true;
        }
        return false;
    }
};