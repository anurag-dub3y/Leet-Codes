class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](const int mid){
            long long req=0LL;
            for(auto &it:piles){
                req+=((1LL*it/mid)+(it%mid!=0));
            }
            return req<=h;
        };
        int low=1, hi=1e9+2;
        while(low<=hi){
            int mid=(low+hi)/2;
            if(check(mid)){
                hi=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};