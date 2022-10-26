class Solution {
public:
    int uniqueLetterString(string s) {
        long long ans=0, n=s.length(), mod=1e9+7;
        vector<long long> l(n,-1), r(n,-1), prev(26,-1), suff(26,n);
        for(int i=0; i<n; i++){
            l[i]=i-prev[s[i]-'A'];
            prev[s[i]-'A']=i;
        }
        for(int i=n-1; i>=0; i--){
            r[i]=suff[s[i]-'A']-i;
            suff[s[i]-'A']=i;
        }
        for(int i=0; i<n; i++){
            ans+=((l[i]*r[i])%mod);
            ans%=mod;
        }
        return ans;
    }
};