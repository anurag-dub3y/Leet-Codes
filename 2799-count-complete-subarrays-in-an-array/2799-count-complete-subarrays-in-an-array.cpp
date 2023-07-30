class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> tmp(begin(nums),end(nums));
        int dist=tmp.size();
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> s;
            for(int j=i; j<nums.size(); j++){
                s.insert(nums[j]);
                if(s.size() == dist) ans++;
            }
        }
        return ans;
    }
};