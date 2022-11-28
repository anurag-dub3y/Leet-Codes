class Solution {
public:
    int pivotInteger(int n) {
        int k=sqrt(n*(n+1)/2);
        return k*k==n*(n+1)/2?k:-1;
    }
};