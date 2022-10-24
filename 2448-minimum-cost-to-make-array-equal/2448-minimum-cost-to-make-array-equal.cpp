class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left=1, right=1000000, x=trinary(nums,cost,left);
        while(left<right){
            long long mid=(left+right)/2;
            long long val1=trinary(nums,cost,mid), val2=trinary(nums,cost,mid+1);
            x=min(val1,val2);
            if(val1<val2){ right=mid; }
            else{ left=mid+1; }
        }
        return x;
    }
    long long trinary(vector<int>& nums, vector<int>& cost, int avg){
        long long ans=0;
        for(int i=0; i<nums.size(); i++){ ans+=1LL*cost[i]*abs(avg-nums[i]); }
        return ans;
    }
};