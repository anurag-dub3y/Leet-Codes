class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price),end(price));
        auto check=[&](int mid){
            if(mid==0){ return true; }
            int i=0, kd=0;
            while(i<price.size() and kd<k){
                int j=lower_bound(begin(price),end(price),price[i]+mid)-price.begin();
                kd++;
                i=j;
                if(kd<k and j==price.size()){ return false; }
            }
            return true;
        };
        int mn=0, mx=price.back()-price[0];
        while(mn<=mx){
            int mid=(mn+mx)/2;
            if(check(mid)){ mn=mid+1; }
            else{ mx=mid-1; }
        }
        return mx;
    }
};


// 1 2 5 8 13 21
// 1  13  21
