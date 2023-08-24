class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        auto distance=[&](int i, int j) {
            int d1 = points[i][0] - points[j][0];
            int d2 = points[i][1] - points[j][1];
            return d1 * d1 + d2 * d2;
        };
        for(int i = 0 ; i < points.size(); ++i) {
            unordered_map<long, int> mp;
            for(int j = 0; j < points.size(); ++j) {
                if(i == j) continue;
                long dis = distance(i,j);
                // Add the counter for existing equal distance here
                ans += mp[dis] * 2;  
                mp[dis]++;
            }
        }
        return ans;
    }
};