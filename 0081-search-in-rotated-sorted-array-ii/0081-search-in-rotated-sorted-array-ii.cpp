class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> s(nums.begin(),nums.end());
        return(s.find(target)!=s.end());
    }
};