typedef vector<int> vii;
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        vii diff(1<<n,1e9), dp(1<<n,1e9);
        for(int mask=1; mask<(1<<n); mask++){
            int mn=17, mx=0, flag=0;
            for(int i=0; i<n; i++){
                if((mask>>i)&1){
                    mn=min(mn,nums[i]);
                    if(nums[i]==mx){ flag=1; break; }
                    mx=nums[i];
                }
            }
            if(!flag){ diff[mask]=mx-mn; }
        }
        dp[0]=0;
        for(int mask=1; mask<(1<<n); mask++){
            for(int submask=mask; submask; submask=(submask-1)&mask){
                if(__builtin_popcount(submask)==n/k){
                   // mask = submask + (mask ^ submask)
                   // mask ^ submask = mask - submask
                   // (mask ^ submask) = elements in mask that are not in submask
                    dp[mask] = min(dp[mask], diff[submask] + dp[mask ^ submask]);
                }
            }
        }
        return dp.back() >= 1e9 ? -1 : dp.back();
    }
};