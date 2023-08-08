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
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
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
        
        vector<pair<int,int>> newPos;
        for(int i=0; i<n; i++){ newPos.push_back({nums[i],i}); }
        sort(begin(newPos),end(newPos));
        
        for(int i=0; i<n; i++){
            int pos=i, oldPos=newPos[i].second;
            // cout<<newPos[i].first<<" was in "<<oldPos<<" and wants to be in "<<pos<<endl;
            if(find(pos)!=find(oldPos)){ return false; }
        }
        
        return true;
    }
};