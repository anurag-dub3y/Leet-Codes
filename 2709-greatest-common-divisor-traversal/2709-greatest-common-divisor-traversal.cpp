class Solution {
public:
    vector<int> par, sz;
    int find(int n){
        if(n==par[n]){ return n; }
        return par[n]=find(par[n]);
    }
    void merge(int a, int b){
        a=find(a), b=find(b);
        if(a==b){ return; }
        if(sz[a]<sz[b]){ swap(sz[a],sz[b]); }
        par[b]=a; 
        sz[a]+=sz[b];
    }
    bool canTraverseAllPairs(vector<int>& nums) {

        int n=nums.size();
        if(n==1){ return true; }
        par=vector<int>(n), sz=vector<int>(n,1);
        for(int i=0; i<n; i++){ par[i]=i; }
        
        unordered_map<int, int> have;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) { return false; }
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    if (have.count(d)) { merge(i, have[d]); } 
                    else { have[d] = i; }
                    while (x % d == 0) { x /= d; } 
                }
            }
            if (x > 1) {
                if (have.count(x)) { merge(i, have[x]); } 
                else { have[x] = i; }
            }
        }
        set<int> pars;
        for(int i=0; i<n; i++){
            int parent=find(i);
            pars.insert(parent);
        }
        return pars.size()==1;
    }
};