class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<long long> pre={0LL};
        for(auto i:nums){ pre.push_back(1LL*pre.back()+i); }
        for(int i=k; i+k<n; i++){
            ans[i]=(1LL*pre[i+k+1]-pre[i-k])/(2*k+1);
        }
        return ans;
    }
};