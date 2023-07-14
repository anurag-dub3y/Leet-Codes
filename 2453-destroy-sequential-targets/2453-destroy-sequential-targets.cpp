class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> umap; //map to store frequencies
        int target=0; // max frequency
        for(int i=0; i<nums.size(); i++){
            target=max(target, ++umap[nums[i]%space]); 
        }
        int ret=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(umap[nums[i]%space]==target)
                ret=min(ret, nums[i]); // min value having max frequency
        }
        return ret;
    }
};