class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& qs) {
        int n=nums.size();
        int evenSum=0;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){ evenSum+=nums[i]; }
        }
        vector<int> ans;
        for (auto &q : qs) {
            if (nums[q[1]] % 2 == 0){ evenSum -= nums[q[1]]; }
            nums[q[1]] += q[0];
            if (nums[q[1]] % 2 == 0){ evenSum += nums[q[1]]; }
            ans.push_back(evenSum);
        }
      return ans;
    }
};