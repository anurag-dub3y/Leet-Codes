class Solution {
public:
    vector<int> LIS1(vector<int>& nums, int n){
        vector<int> lis(n,1);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){ lis[i]=max(lis[i],lis[j]+1); }
            }
        }
        return lis;
    }
    vector<int> LIS2(vector<int>& nums, int n){
        vector<int> lis(n,1);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j]){ lis[i]=max(lis[i],lis[j]+1); }
            }
        }
        return lis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        // First find LIS for each index (nums[i] should be the largest element in it)
        // Reverse nums and again find LIS
        // Traverse the array and find max sum of fwd and bwd LIS
        // ans=nums.size()-(maxSum-1)
        int n=nums.size();
        vector<int> v1=LIS1(nums,n), v2=LIS2(nums,n);
        int maxSum=0;
        for(int i=0; i<n; i++){
            // cout<<v1[i]<<' '<<v2[i]<<'\n';
            if(v1[i]!=1 and v2[i]!=1){
                maxSum=max(maxSum,v1[i]+v2[i]);
            }
        }
        // cout<<'\n';
        return n-(maxSum-1);
    }
};