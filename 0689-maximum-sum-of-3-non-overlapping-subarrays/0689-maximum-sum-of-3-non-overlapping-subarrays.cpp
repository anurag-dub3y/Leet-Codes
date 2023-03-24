class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), mx=0;
        vector<int> pre(n+1,0), ans;
        for(int i=1; i<=n; i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        vector<int> preL(n,0), preR(n,n-k);
        int mxL=pre[k]-pre[0], mxR=pre[n]-pre[n-k];
        for(int i=k; i<n; i++){
            if(pre[i+1]-pre[i-k+1]>mxL){
                preL[i]=i-k+1;  // The largest subarray to the left of i and of size k starts from here
                mxL=pre[i+1]-pre[i-k+1];
                // cout<<mxL<<' ';
            }
            else{ preL[i]=preL[i-1]; }
        }
        // cout<<'\n';
        for(int i=n-k-1; i>=0; i--){
            if(pre[i+k]-pre[i]>=mxR){
                preR[i]=i;
                mxR=pre[i+k]-pre[i];
                // cout<<mxR<<' ';
            }
            else{ preR[i]=preR[i+1]; }
        }
        // cout<<'\n';
        int maxSum=0;
        for (int i = k; i <= n-2*k; i++) {
            int l = preL[i-1], r = preR[i+k];
            int tot = (pre[i+k]-pre[i]) + (pre[l+k]-pre[l]) + (pre[r+k]-pre[r]);
            if (tot > maxSum) {
                maxSum = tot;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};