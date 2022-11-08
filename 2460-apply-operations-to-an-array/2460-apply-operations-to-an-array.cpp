class Solution {
public:
    vector<int> applyOperations(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]*=2; nums[i]=0;
            }
        }
        int i=0, z=0;
        for(auto it:nums){
            if(it==0){ z++; }
            else{ nums[i++]=it; }
        }
        while(i<nums.size()){ nums[i++]=0; }
        return nums;
    }
};