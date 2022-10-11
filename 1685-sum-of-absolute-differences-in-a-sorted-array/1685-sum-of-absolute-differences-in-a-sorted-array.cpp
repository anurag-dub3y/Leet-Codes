class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n), pre(n,0), suff(n,0);
        pre[0]=nums[0]; 
        suff[n-1]=nums[n-1];
        for(int i=1; i<n; i++){ pre[i]=pre[i-1]+nums[i]; }
        for(int i=n-2; i>=0; i--){ suff[i]=suff[i+1]+nums[i]; }
        for(int i=0; i<n; i++){
            ans[i]=nums[i]*(i+1)-pre[i];
            if(i!=n-1){ ans[i]+=suff[i+1]-nums[i]*(n-1-i); }
        }
        return ans;
    }
};