class Solution {
public:
    bool RabinKarp(string &s, string &t){
        int m=s.length(), n=t.length();
        long long p=31, pow=1, mod=1e9+7, targetHash=0;
        for(auto &i:t){
            targetHash=(targetHash+(i-'a'+1)*pow)%mod;
            pow=(pow*p)%mod;
        }
        
        vector<long long> pre(m+1);
        vector<long long> powers(m+1);
        
        pre[0]=s[0]-'a'+1; powers[0]=1; pow=p;
        for(int i=1; i<=m; i++){
            pre[i]=(pre[i-1] + (s[i-1]-'a'+1)*pow)%mod;
            powers[i]=pow;
            pow=(pow*p)%mod;
        }
        
        int l=0, r=n-1;
        while(r<=m){
            long long window=pre[r];
            if(l>0){
                window=(window - pre[l-1] + mod)%mod;
            }
            if(window==((targetHash)*powers[l])%mod){ 
                // cout<<s.substr(l-1,n)<<' '<<t<<endl;
                if(l>0 and t==s.substr(l-1,n)) return true; 
            }
            l++; r++;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b){ return 1; }
        int cnt=1;
        string A=a;
        while(A.length()<b.length()){
            A+=a; cnt++;
        }
        if(A==b){ return cnt; }
        if(RabinKarp(A,b)){ return cnt; }
        A+=a;
        if(RabinKarp(A,b)){ return cnt+1; }
        return -1;
    }
};