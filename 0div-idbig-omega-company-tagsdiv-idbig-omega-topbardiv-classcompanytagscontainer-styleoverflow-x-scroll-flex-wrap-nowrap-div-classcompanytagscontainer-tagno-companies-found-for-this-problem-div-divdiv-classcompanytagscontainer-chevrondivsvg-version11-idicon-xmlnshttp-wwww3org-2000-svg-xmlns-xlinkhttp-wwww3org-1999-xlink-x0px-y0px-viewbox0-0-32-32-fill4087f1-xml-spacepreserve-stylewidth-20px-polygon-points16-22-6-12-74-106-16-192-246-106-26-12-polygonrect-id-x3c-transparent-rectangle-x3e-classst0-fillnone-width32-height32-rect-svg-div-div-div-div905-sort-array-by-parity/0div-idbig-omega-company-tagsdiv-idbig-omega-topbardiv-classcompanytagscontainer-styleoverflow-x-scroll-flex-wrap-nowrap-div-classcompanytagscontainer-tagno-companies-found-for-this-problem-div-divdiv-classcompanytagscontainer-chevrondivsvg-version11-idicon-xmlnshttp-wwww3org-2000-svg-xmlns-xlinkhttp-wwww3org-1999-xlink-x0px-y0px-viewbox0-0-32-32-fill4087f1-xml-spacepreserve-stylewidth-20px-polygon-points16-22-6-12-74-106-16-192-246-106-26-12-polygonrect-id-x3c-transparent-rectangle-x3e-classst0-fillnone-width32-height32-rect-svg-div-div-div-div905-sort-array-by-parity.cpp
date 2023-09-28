class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        for(auto &i:nums){
            if(i%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        int k=0;
        for(auto &i:even) nums[k++]=i;
        for(auto &i:odd) nums[k++]=i;
        return nums;
    }
};