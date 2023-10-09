class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target)){
            return {-1, -1};
        }
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return {x,y};
    }
};