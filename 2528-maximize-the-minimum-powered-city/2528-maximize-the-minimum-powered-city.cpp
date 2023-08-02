#define ll long long int
class Solution {
public:
    bool check(vector<int> &v,ll m,ll r,ll k){
        ll cur = 0;
        int i = 0, n = v.size();
        for(i = 0; i < r; i++){
            cur += v[i];
        }
        int a,b;
        vector<ll> add(n,0);
        for(i = 0; i < n; i++){
            if(i+r<n){
                cur += v[i+r];
                cur += add[i+r];
            }
            if(m > cur){
                ll need = m-cur;
                if(need>k){ return false; }
                k -= need;
                cur = m;
                a = n-1,b = r+i;
                add[min(a,b)] = need;
            }
            if(i-r>=0){
                cur -= v[i-r];
                cur -= add[i-r];
            }
        }
        return true;
    }
    ll maxPower(vector<int>& v, int r, int k) {
        ll mx = 1e11, mn = 0, mid;
        while(mn<=mx){
            mid=(mx+mn)/2;
            if(check(v,mid,r*1LL,k*1LL)){
                mn = mid+1;
            }
            else{ mx = mid-1; }
        }
        return mx;
    }
};