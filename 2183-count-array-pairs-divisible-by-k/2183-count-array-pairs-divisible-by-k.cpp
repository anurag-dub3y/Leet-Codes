class Solution {
public:
    using ll=long long;
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll, ll> gcdCount;
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ll currgcd = __gcd(nums[i], k);
            for (auto &[gc_d, count] : gcdCount){
                if ((currgcd * gc_d) % k == 0){ ans += count; }
            }
            gcdCount[currgcd]++;
        }
        return ans;
    }
};