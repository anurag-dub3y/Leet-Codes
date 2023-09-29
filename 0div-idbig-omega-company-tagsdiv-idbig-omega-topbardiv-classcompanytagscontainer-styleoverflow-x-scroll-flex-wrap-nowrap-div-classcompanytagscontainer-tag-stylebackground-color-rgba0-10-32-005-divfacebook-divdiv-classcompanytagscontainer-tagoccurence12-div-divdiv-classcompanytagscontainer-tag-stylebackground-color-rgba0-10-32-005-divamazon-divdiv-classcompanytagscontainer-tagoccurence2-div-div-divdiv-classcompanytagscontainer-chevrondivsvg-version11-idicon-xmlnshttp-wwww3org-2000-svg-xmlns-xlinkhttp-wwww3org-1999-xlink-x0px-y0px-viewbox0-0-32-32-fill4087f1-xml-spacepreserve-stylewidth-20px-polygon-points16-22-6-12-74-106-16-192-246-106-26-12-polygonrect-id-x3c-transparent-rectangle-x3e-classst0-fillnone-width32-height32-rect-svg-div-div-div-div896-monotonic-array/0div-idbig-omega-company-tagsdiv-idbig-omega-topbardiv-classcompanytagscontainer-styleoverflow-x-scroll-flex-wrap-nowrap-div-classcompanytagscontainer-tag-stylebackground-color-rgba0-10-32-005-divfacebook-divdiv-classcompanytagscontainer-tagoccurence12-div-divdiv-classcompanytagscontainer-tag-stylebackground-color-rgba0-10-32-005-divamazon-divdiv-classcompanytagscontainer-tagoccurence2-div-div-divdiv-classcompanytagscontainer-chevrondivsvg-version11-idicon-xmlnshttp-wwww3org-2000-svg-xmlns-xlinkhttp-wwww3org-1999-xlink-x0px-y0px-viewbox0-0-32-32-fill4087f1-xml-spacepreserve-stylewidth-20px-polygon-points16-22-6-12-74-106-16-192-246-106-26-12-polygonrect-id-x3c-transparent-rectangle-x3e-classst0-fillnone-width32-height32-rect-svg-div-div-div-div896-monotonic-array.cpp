class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(is_sorted(begin(nums),end(nums))){ return true; }
        reverse(begin(nums),end(nums));
        if(is_sorted(begin(nums),end(nums))){ return true; }
        return false;
    }
};