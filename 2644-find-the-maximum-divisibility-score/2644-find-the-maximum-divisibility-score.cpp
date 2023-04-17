class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(begin(divisors),end(divisors));
        int val=0, ans=divisors[0];
        for(auto d:divisors){
            int cnt=0;
            for(auto i:nums){
                cnt+=(i%d==0);
            }
            if(cnt>val){
                val=cnt; ans=d;
            }
        }
        return ans;
    }
};