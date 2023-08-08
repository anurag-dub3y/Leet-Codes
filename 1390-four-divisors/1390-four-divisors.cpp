class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // sort(begin(nums),end(nums));
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int cnt=0, curr=0;
            for(int j=1; j*j<=nums[i]; j++){
                if(nums[i]%j==0){
                    cnt++;
                    curr+=j;
                    if(j*j!=nums[i]){ cnt++; curr+=nums[i]/j; }
                }
            }
            if(cnt==4){ ans+=curr; }
        }
        return ans;
    }
};