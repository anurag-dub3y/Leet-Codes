class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> c(n);
        int mx=nums[0];
        for(int i=0; i<n; i++){
            mx=max(nums[i],mx);
            c[i]=nums[i]+mx;
        }
        vector<long long> ans(n);
        for(int i=0; i<n; i++){
            if(i==0){ ans[i]=c[0]; }
            else{ ans[i]=ans[i-1]+c[i]; }
        }
        return ans;
    }
};