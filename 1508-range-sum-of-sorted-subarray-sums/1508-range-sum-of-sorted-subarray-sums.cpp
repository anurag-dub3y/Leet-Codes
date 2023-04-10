class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        vector<int> pre={0};
        for(int i=0; i<n; i++){ pre.push_back((pre.back()+nums[i])%mod); }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                sums.push_back((pre[j+1]-pre[i]+mod)%mod);
            }
        }
        sort(begin(sums),end(sums));
        long long ans=0LL;
        for(int i=left-1; i<right; i++){
            ans+=sums[i];
            ans%=mod;
        }
        return ans;
    }
};