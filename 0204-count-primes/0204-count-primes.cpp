class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int ans=0;
        for (int i=2; i<n; i++){
            if(notPrime[i]){ continue; }
            ans++;
            for(long j=(long)i*i; j<n; j+=i){ notPrime[j]=true; }
        }
        return ans;
    }
};