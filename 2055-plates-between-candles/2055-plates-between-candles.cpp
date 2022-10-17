class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int> sum(n+1), r(n+1, INT_MAX), l(n+1), ans;
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (s[i] == '|');
            l[i + 1] = s[i] == '|' ? i : l[i];
        }
        for (int i = n-1; i >= 0; --i){
            r[i] = (s[i] == '|') ? i : r[i + 1];
        }
        for (auto &q : queries) {
            int leftInd = r[q[0]], rightInd = l[q[1] + 1];
            ans.push_back(leftInd < rightInd ? rightInd - leftInd - (sum[rightInd] - sum[leftInd]) : 0);
        }
        return ans;
    }
};