class Solution {
public:
    string subStrHash(string s, int pp, int mod, int k, int hashValue) {
        long long hash=0, p=1, n=s.length();
        string ans;
        for(int i=n-k; i<n; i++){
            hash=(hash+(s[i]-'a'+1)*p)%mod;
            p=(p*pp)%mod;
        }
        // p is now pp^k and thats the power of the last term which we'll subtract
        if(hash==hashValue){ ans=s.substr(n-k); }
        for(int i=n-k-1; i>=0; i--){
            hash = ((hash*pp+((s[i]-'a')+1))%mod - ((s[i+k]-'a')+1)*p%mod + mod) % mod;
            if (hash == hashValue) {
                ans=s.substr(i,k);
            }
        }
        return ans;
    }
};