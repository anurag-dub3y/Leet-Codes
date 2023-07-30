class Solution {
public:
    int find(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int count = 0, start = 0, end = 0;
        while (end < n) {  
            cnt[nums[end]]++;
            while (cnt.size() > k) { 
                cnt[nums[start]]--;  
                if (cnt[nums[start]] == 0) { 
                    cnt.erase(nums[start]);
                }
                start++;  
            }
            count += end - start + 1;  
            end++;  
        }
        return count;  
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums, k) - find(nums, k - 1);
    }
};