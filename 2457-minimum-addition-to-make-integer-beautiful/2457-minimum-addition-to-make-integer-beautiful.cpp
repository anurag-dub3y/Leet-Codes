class Solution {
public:
    long long digSum(long long n){
        long long ans=0;
        while(n){ ans+=n%10; n/=10; }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long x=n, i=1;
        while(digSum(n)>target){
            n=n/10+1; i*=10;
        }
        return n*i-x;
    }
};