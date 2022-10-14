class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()==i-k){ dq.pop_front(); }
            while(!dq.empty() && nums[dq.back()]<nums[i]){ dq.pop_back(); }
            if(!dq.empty() && i>=k-1){ ans.push_back(nums[dq.front()]); }
            else if(i>=k-1){ ans.push_back(nums[i]); }
            dq.push_back(i);
        }
        return ans;
    }
};