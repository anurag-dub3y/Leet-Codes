class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        vector<long long> pre={0};
        for(auto i:nums){ pre.push_back(pre.back()+i); }
        // for(auto i:pre){ cout<<i<<' '; } cout<<'\n';
        vector<long long> ans;
        for(auto q:queries){
            if(q<nums[0]){ ans.push_back(1LL*pre.back()-1ll*n*q); continue; }
            else if(q>nums.back()){ ans.push_back(n*q-pre.back()); continue; }
            long long r=upper_bound(nums.begin(),nums.end(),q)-nums.begin();
            long long l=lower_bound(nums.begin(),nums.end()-1,q)-nums.begin();
            long long rSum=abs(1LL*(n-r)*q-pre.back()+pre[r]);
            long long lSum=abs(1LL*(l)*q-pre[l]+pre[0]);
            // cout<<l<<' '<<r<<'\n';
            // cout<<lSum<<','<<rSum<<' ';
            ans.push_back(lSum+rSum);
        }
        // cout<<'\n';
        return ans;
    }
};

// 1 3 6 8
// 5 5 5 5 
// 6+4