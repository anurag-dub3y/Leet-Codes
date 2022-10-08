class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0; i<n-2; i++){
            if(i==0 or (nums[i]!=nums[i-1])){
                int l=i+1, r=n-1;
                while(l<r){
                    int currSum=nums[l]+nums[i]+nums[r];
                    if(abs(ans-target)>abs(currSum-target)){ ans=currSum; }
                    if(currSum>target){ r--; }
                    else if(currSum<target){ l++; }
                    else{ return target; }
                }
            }
        }
        return ans;
    }
};