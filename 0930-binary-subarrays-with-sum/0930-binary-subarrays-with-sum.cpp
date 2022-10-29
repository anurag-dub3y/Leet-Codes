class Solution {
public:
    int atMostGoal(vector<int>& nums, int goal){
        int i=0, j=0, currSum=0, ans=0, n=nums.size();
        if(goal<0){ return 0; }
        while(i<n){
            currSum+=nums[i];
            while(currSum>goal){
                currSum-=nums[j++];
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostGoal(nums,goal)-atMostGoal(nums,goal-1);
    }
};