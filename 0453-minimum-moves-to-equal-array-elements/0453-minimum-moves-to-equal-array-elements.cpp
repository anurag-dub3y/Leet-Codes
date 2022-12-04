class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int currSum=accumulate(nums.begin(),nums.end(),0);
        return currSum-n*(*min_element(nums.begin(),nums.end()));
    }
};