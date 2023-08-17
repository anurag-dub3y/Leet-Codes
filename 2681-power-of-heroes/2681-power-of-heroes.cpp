class Solution {
public:
    long long mod=1e9+7;
    int binpow(int a, int b){
        long long ans=1LL;
        while(b){
            if(b&1){ ans=(ans*a)%mod; }
            a=(1LL*a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    int sumOfPower(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long ans=0LL, runningSum=0LL;
        for(int i=0; i<nums.size(); i++){
            ans=(1LL*ans+(1LL*nums[i]%mod*nums[i]%mod*(1LL*runningSum+nums[i])%mod)%mod)%mod;      
            runningSum=(2LL*runningSum+nums[i])%mod;
        }
        return ans;
    }
};

 