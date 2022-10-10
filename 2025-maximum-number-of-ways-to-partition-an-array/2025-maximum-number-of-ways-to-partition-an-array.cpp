class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> p(n), s(n);
        p[0]=nums[0];
        for(int i=1; i<n; i++){ p[i]=p[i-1]+nums[i]; }
        s[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){ s[i]=s[i+1]+nums[i]; }
        
        long long ans = 0;
        unordered_map<long long,long long> left, right;
        
        for(int i=0; i<n-1; ++i){ right[p[i] - s[i+1]]++; }
        if(right.count(0)){ ans = right[0]; }   // No vhange in nums
        
        for(int i=0; i<n; ++i){
            long long curr = 0, diff = k-nums[i];
            if(left.count(diff)){ curr+=left[diff]; }
            if(right.count(-diff)){ curr+=right[-diff]; }
            ans = max(ans, curr);
            if(i<n-1){
                long long dd = p[i]-s[i+1]; 
                left[dd]++; right[dd]--;
                if(right[dd] == 0) right.erase(dd);
            }
        }
        return ans;

    }
};