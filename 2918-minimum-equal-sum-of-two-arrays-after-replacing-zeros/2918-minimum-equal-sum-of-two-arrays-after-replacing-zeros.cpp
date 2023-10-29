class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(nums1.begin(), nums1.end(), 0LL), s2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int c1 = count(nums1.begin(), nums1.end(), 0), c2 = count(nums2.begin(), nums2.end(), 0);
        if (s1 + c1 == s2 + c2) return s1 + c1;
        else if (s1 + c1 > s2 + c2) {
            if (c2 == 0) return -1;
            return s1 + c1;
        }
        return c1 == 0? -1: s2 + c2;
    }
};