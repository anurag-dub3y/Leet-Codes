class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        #define int long long
        int n=nums.size(), ans=0;
        vector<int> count(n+1,0);
        for(int i=1; i<=n; i++){
            count[i]=count[i-1]+(nums[i-1]%mod==k);
        }
        map<int,int> mp;
        for(int i=1; i<=n; i++){
            int mod_val = count[i] % mod;
            if (mod_val == k){ ans++; }
            int find = mod_val - k;
            if (find < 0) { find += mod; }
            ans += mp[find];
            mp[mod_val]++;
        }
        return ans; 
        #undef int
    }
};
