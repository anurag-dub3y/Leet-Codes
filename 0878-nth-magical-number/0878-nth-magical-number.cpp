class Solution {
public:
    int m=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long LCM=(a*b)/gcd(a,b);
        auto find=[&](long long mid){
            return (mid/a) + (mid/b) - (mid/LCM);
        };
        long long low=1, high=1e18, ans=1e18;
        while(low<=high){
            long long mid=(low+high)/2;
            // cout<<mid<<' ';
            long long cnt=find(mid);
            if(cnt<n){ low=mid+1; }
            else{ high=mid-1; ans=mid; }
        }
        return ans%m;
    }
};