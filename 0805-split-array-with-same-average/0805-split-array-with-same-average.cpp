class Solution {
public:
    unordered_map<string, int> mp;
    bool find(vector<int>& nums, int i, int n, int sum, int n1){
        if(n1 == 0) return sum == 0;
        if(i == n) return false;
        string key = to_string(i) + "#" + to_string(n1) + "#" + to_string(sum);
        if(mp.count(key)) return mp[key];
        if(nums[i] <= sum) {
            return mp[key] = find(nums, i + 1, n, sum - nums[i], n1 - 1) || find(nums, i + 1, n, sum, n1);
        }
        else return mp[key] = find(nums, i + 1, n, sum, n1);
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) { sum += nums[i]; }

        // check for every possible size of subset from 1 to n - 1
        for(int n1 = 1; n1 < n; n1++) {
            if((sum * n1) % n == 0) {
                int req_sum = (sum * n1) / n;
                if(find(nums, 0, n, req_sum, n1))
                    return true;
            }
        }
        return false;
    }
};