class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=1+(min_element(begin(nums),end(nums))-begin(nums));
        int mx=1+(max_element(begin(nums),end(nums))-begin(nums));
        int n=nums.size();
        if(n==1){ return 1; }
        return min({ max(mn,mx), n+1-min(mn,mx), min(mn,mx)+n+1-max(mn,mx) });
    }
};