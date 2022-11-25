class Solution {
public:
    int mod=1e9+7;
    int totalStrength(vector<int>& s) {
        int n=s.size();
        vector<int> left(n,-1), right(n,n);
        stack<int> lefts, rights;
        // lefts.push(0); rights.push(n-1);
        left[0]=1; right[n-1]=1;
        for(int i=0; i<n; i++){
            while(!lefts.empty() && s[lefts.top()]>=s[i]){ lefts.pop(); }
            if(lefts.empty()){ left[i]=-1; }
            else{ left[i]=lefts.top(); }
            lefts.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!rights.empty() && s[rights.top()]>s[i]){ rights.pop(); }
            if(rights.empty()){ right[i]=n; }
            else{ right[i]=rights.top(); }
            rights.push(i);
        }
        
        vector<long> pre(n+1,0L);
        for(int i=0; i<n; i++){ pre[i+1]=(pre[i]+s[i])%mod; }

        vector<long> x(n+2,0L);
        for(int i=0; i<=n; i++){ x[i+1]=(x[i]+pre[i])%mod; }

        long long ans=0;
        for(int i=0; i<n; i++){
            ans += (1LL* (x[right[i] + 1] - x[i + 1])* 1LL * (i - left[i]) % mod + mod * 2 - 
               1LL * (x[i + 1] - x[left[i] + 1]) * (right[i] - i) % mod) % mod * s[i] % mod;
            ans %= mod;
        }
        return (int)ans;
    }
};

/*
L = len_l[i]
R = len_r[i]
total_R = (psps[i + R - 1] - psps[i - 1]) * L
total_L = (psps[i - 1] - psps[max(-1, i - L - 1)]) * R
ans = (ans + strength[i] * (total_R - total_L)) % mod
*/