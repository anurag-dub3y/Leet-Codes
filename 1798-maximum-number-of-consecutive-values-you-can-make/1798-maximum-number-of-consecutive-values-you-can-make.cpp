class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(begin(coins),end(coins));
        int ans=1;
        for(auto &a:coins) {
            if(a > ans){ break; }
            ans += a;
        }
        return ans;
    }
};
