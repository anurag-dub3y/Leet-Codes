class Solution {
public:
    int minimumOperations(string &nums) {
        int n = nums.size();
        int ans = n;
        for(int j=n-1;j>=0;j--){
            if(nums[j]=='0'){
                for(int i=j-1;i>=0;i--){
                    if(nums[i]=='5' || nums[i]=='0') ans = min(ans,n-j-1 + j-i-1);
                }
                ans = min(ans, n-1);
            }
            if(nums[j]=='5'){
                for(int i=j-1;i>=0;i--){
                    if(nums[i]=='2' || nums[i]=='7') ans = min(ans,n-j-1 + j-i-1);
                }
            }
        }
        return ans;
    }
};