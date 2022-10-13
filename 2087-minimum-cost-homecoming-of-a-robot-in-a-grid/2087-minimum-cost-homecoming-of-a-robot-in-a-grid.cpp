class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0, dr = s[0] < h[0] ? 1 : -1, dc = s[1] < h[1] ? 1 : -1;
        for (int r = s[0]; r != h[0]; r += dr)
            res += rowCosts[r + dr];
        for (int c = s[1]; c != h[1]; c += dc)
            res += colCosts[c + dc];
        return res;
    }
};