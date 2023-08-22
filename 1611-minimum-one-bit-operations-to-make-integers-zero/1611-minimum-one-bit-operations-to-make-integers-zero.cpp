class Solution {
public:
    int minimumOneBitOperations(int n) {
        long long ans=0LL;
        while(n){
            ans^=n;
            n>>=1;
        }
        return ans;
    }
};