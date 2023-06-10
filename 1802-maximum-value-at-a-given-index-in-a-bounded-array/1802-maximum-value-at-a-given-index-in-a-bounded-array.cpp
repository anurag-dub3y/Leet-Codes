class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto check=[&](int i, int maxSum, int m) {
            for (int d = 1; maxSum >= 0 && d < m && i + d < n; ++d) { maxSum -= m - d; }
            for (int d = 1; maxSum >= 0 && d < m && i - d >= 0; ++d){ maxSum -= m - d; }
            return maxSum >= 0;
        };
        int l = 0, r = maxSum;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(index, maxSum - n - mid, mid)){ l = mid; }
            else{ r = mid - 1; }
        }
        return l + 1;
    }
};