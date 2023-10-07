class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        long long sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += 1LL*nums[i];
            nums.push_back(nums[i]);
        }

        int res = 0;
        res = n*(1LL*target / sum) ;
        target = (1LL*target) % sum;
        
        int i=0, j=0;
        int curr = 0;
        int mn = INT_MAX;
        while(i < 2*n){
            if(curr < target){
              curr += nums[i];
              i++;
            }
            else if(curr == target){
                mn = min(mn, i- j);
                curr += nums[i];
                i++;
                curr -= nums[j];
                j++;
            }
            else if(curr > target){
                curr -= nums[j];
                j++;
            }
        }
        if(mn == INT_MAX) return -1;
        
        res += mn;
        return res;
    }
};