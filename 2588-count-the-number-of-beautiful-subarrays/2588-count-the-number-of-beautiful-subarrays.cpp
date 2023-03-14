class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long int,long long int> mp;
        long long int ans=0, x=0;
        mp[0]=1;
        for(auto &i: nums){
            x^=i;
            if(mp.count(x)){ ans+=mp[x]; }
            mp[x]++;
        }
        return ans;
    }
};