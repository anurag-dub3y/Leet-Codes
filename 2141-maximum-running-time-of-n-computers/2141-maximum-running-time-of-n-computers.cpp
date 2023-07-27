class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        auto check=[&](long long mid){
            long long sum=0LL;
            for(auto &b:batteries){
                sum+=min((long long)b,mid);
            }
            return sum>=1LL*n*mid;
        };
        long long high=accumulate(begin(batteries),end(batteries),0LL);
        long long low=0;
        while(low<=high){
            long long mid=(low+high+1)/2;
            if(check(mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};