class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0, sum=0, i=0, j=0, n=nums.size();
        while(i<n){
            sum+=nums[i];
            while(sum*(i-j+1)>=k){
                sum-=nums[j++];
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
};