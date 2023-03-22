class Solution {
public:
    void dfs(int i, unordered_map<int, int>& cur, vector<int>& nums, int k, int & ans) {
        int n = nums.size();
        if (i == n) { ans++; return; }
        dfs(i + 1, cur, nums, k, ans);

        if (cur[nums[i] + k] == 0 && cur[nums[i] - k] == 0) {
            cur[nums[i]]++;
            dfs(i + 1, cur, nums, k, ans);
            cur[nums[i]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> cur;
        int ans = 0;
        dfs(0, cur, nums, k, ans);
        return ans - 1;
    }
};