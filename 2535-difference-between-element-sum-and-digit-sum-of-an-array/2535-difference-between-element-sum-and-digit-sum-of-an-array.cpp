class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elSum=accumulate(nums.begin(),nums.end(),0);
        int dSum=0;
        for(auto i:nums){
            string s=to_string(i);
            for(auto j:s){ dSum+=(j-'0'); }
        }
        return abs(elSum-dSum);
    }
};