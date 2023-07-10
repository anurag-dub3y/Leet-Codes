using ull=unsigned long long;
ull power=131, mod=1e9+9;
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.length();
        vector<ull> p(n+2,1), hsh(n+1,0);        
        for(int i=0; i<=n; i++){ p[i+1]=(1LL*p[i]*power)%mod; }
        for(int i=0; i<n; i++){ hsh[i+1]=(1LL*hsh[i]*power+(text[i]-'a'+1))%mod; }
        auto get=[&](int l, int r){
		    return (hsh[r] - 1LL * hsh[l] * p[r-l] % mod + mod) % mod;
	    };
        int ans=0;
        unordered_set<int> st;
		for (int i = 0; i < n; i++){
			for (int l = 2; i + l <= n; l += 2){
				int mid = i + l / 2;
				ull a = get(i, mid);
				ull b = get(mid, i + l);
				if(a == b){ st.insert(a); }
			}
		}
		return st.size();
    }
};