class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(begin(nums),end(nums));
        long ans=0, mx=0, i=0;
        while(mx<n){
            // 1 2 3 5 ... we can add these to form 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 and so on 
            if(i<nums.size() and nums[i]<=mx+1){ mx+=nums[i++]; }
            else{
                
                // If next number is 13, the streak breaks and so we need to add 12
                // No mx = 11 (from prev) + 12 = 23
                ans++;
                mx+=mx+1;
            }
        }
        return ans;
    }
};

