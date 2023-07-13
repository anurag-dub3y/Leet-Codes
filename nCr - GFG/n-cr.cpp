//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod=1e9+7;
    long long binpowmod(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1){ res = res * a % m; }
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int modInverse(int a, int mod) { return binpowmod(a, mod-2, mod); }
    int nCr(int n, int r){
        long long prod = 1LL;
        for(int i = 1; i <= r; i++){
            prod = (prod%mod * (n - r + i)%mod *modInverse(i,mod))%mod;
        }
        return prod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends