class Union{
public:
    // I dont think we need the parent
    vector<long long> par, sz;
    long long mxSize;
    Union(int _n){
        par=vector<long long>(_n+1), sz=vector<long long>(_n+1,0);
        for(int i=0; i<_n; i++){ par[i]=i; }
        mxSize=0;
    }
    long long findPar(long long n){
        if(par[n]==n){ return n; }
        return par[n]=findPar(par[n]);
    }
    void join(int a, int b){
        a=findPar(a), b=findPar(b);
        if(sz[a]<sz[b]){ swap(a,b); }
        par[b]=a; sz[a]+=sz[b];
        mxSize=max(mxSize,sz[a]);
    }
    void init(int a, int val){
        sz[a]=val;
        mxSize=max(mxSize,sz[a]);
    }
};
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        Union U(n);    
        vector<long long> tmp(n,0), ans(n,0);
        for(int i=n-1; i>=0; i--){
            ans[i]=U.mxSize;
            U.init(q[i],nums[q[i]]);
            if(q[i]>0 and U.sz[q[i]-1]!=0){ U.join(q[i]-1,q[i]); }
            if(q[i]<n-1 and U.sz[q[i]+1]!=0){ U.join(q[i]+1,q[i]); }
        }
        return ans;
    }
};