class Solution {
public:
    int mod=1e9+7;
    int fact[100005], infact[100005];
    int ans=1;
    int binpow(int a, int b, int p){
        int res = 1;
        a %= p;
        while (b) {
            if (b & 1){ res = 1LL * (1LL * res * a) % p; }
            a = 1LL * (1LL * a * a) % p;
            b >>= 1;
        }
        return res;
    }
    void precompute(){
        int n = 100000;
        fact[0] = 1;
        for (int i = 1; i <= n; ++i){ fact[i] = (1LL*fact[i-1]*i) % mod; }
        infact[n] = binpow(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; --i){
            infact[i] = (1LL* infact[i + 1] * (i + 1)) % mod; // computing all factorial inverses in O(N)
        }
    }
    void returnVal(string &s){
        unordered_map<char,int> u;
        ans=(1LL*ans*fact[s.size()])%mod;
        for(auto i:s){ ++u[i]; }
        for(auto j:u){ ans=(1LL*ans*infact[j.second])%mod; }
        // Here factorials value are large so we can't perform divide instead we can multiply with their inverse.
        return;
    }
    int countAnagrams(string s) {
        precompute();
        string k="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ' or i==s.length()-1){
                if(i==s.length()-1){ k+=s[i]; }
                returnVal(k);
                // cout<<k<<' '<<ans<<' ';
                k="";
            }
            else{ k+=s[i]; }
        }
        return ans;
    }
};