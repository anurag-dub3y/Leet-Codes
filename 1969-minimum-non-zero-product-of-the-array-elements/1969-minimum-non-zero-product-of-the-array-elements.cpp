class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    
    // val = 2^p -1
    // To get minimum non-zero product, we can convert the (val/2) numbers to '1' by swapping the bits.
    // In this process, val/2 numbers can be converted into '1' and val/2 numbers can be converted into val-1 and only one number val remains same.

    int power(ll x, ll times){
        if(times==0){
            return 1;
        }
        ll temp = power(x,times/2);
        temp = (temp*temp)%mod;
        if(times%2){
            temp = (temp*(x%mod))%mod;
        }
        return temp%mod;
    }
    int minNonZeroProduct(int p) {
        ll x = (1ll<<p)-1;
        return  (x%mod)*power(x-1, x/2)%mod;  
    }
};