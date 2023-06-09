class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        vector<int> left(begin(nums),begin(nums)+n), right(begin(nums)+n,end(nums));
        vector<vector<int>> lSums(n+1);
        for(int mask=0; mask<(1<<n); mask++){
            int chosen=__builtin_popcount(mask), sum=0;
            for(int i=0; i<n; i++){
                if((1<<i)&mask){ sum+=left[i]; }
                else{ sum-=left[i]; }
            }
            lSums[chosen].push_back(sum);
        }
        for(auto &sums:lSums){ sort(begin(sums),end(sums)); }
        int ans=INT_MAX;
        for(int mask=0; mask<(1<<n); mask++){
            int chosen=n-__builtin_popcount(mask), sum=0;
            for(int i=0; i<n; i++){
                if((1<<i)&mask){ sum+=right[i]; }
                else{ sum-=right[i]; }
            }
            auto it = lower_bound(lSums[chosen].begin(), lSums[chosen].end(), -sum); 
            if (it!=lSums[chosen].begin()){ ans = min(ans, abs(sum + *prev(it))); }
            if (it!=lSums[chosen].end()){ ans = min(ans, abs(sum + *it)); }
        }
        return ans;
    }
};