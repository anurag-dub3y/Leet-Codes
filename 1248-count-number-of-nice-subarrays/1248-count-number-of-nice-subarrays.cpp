class Solution {
public:
     int numberOfSubarrays(vector<int>& nums, int k) {
         int ans=0;
         deque<int> deq = { -1 };
         for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) deq.push_back(i);
            if (deq.size() > k + 1) deq.pop_front();
            if (deq.size() == k + 1) ans += deq[1] - deq[0];
         }
        return ans;
     }
};