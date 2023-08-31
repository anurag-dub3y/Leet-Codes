class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1);
        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            maxReach[start] = max(maxReach[start], end);
        }
        
        int taps = 0, currEnd = 0, nextEnd = 0;
        for (int i = 0; i <= n; i++) {
            if (i > nextEnd) { return -1; }
            if (i > currEnd) {
                taps++;
                currEnd = nextEnd;
            }
            nextEnd = max(nextEnd, maxReach[i]);
        }
        return taps;
    }
};