class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod=1, z=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){ prod*=nums[i]; }
            else{ z++; }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                if(z==0){ nums[i]=prod/nums[i]; }
                else{ nums[i]=0; }
            }
            else{
                nums[i]=(z>1)?0:prod;
            }
        }
        return nums;
    }
};