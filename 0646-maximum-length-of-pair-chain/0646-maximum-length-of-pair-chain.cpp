class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        int cnt = 0;
        vector<int>& last = pairs[0];
        for (int i=0; i<pairs.size(); i++) {
            if (i==0 || pairs[i][0]>last[1]) {
                last=pairs[i];
                cnt++;
            }
        }
        return cnt;
    }
};