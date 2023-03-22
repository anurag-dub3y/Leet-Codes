class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long mnT=0, maxT=1e14, ans=maxT;
        auto check=[&](const long long &mid){
            long long v=0;
            for(int &r:ranks){
                long long x=sqrt(1LL*mid/r);
                v+=x;
            }
            return v>=cars;
        };
        while(mnT<=maxT){
            long long mid=mnT+(maxT-mnT)/2;
            if(check(mid)){ ans=min(ans,mid); maxT=mid-1; }
            else{ mnT=mid+1; }
        }
        return ans;
    }
};