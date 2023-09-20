class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        if(is_sorted(begin(nums),end(nums))){ return 0; }
        for(int i=nums.size(); i>=0; i--){
            bool v1=is_sorted(begin(nums),begin(nums)+i);
            bool v2=is_sorted(begin(nums)+i,end(nums));
            if(v1 && v2 && nums.back()<nums[0]){ return nums.size()-i; }
        }
        return -1;
    }
};