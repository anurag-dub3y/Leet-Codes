class Solution {
public:
    // using ull=unsigned long long int;
    // int longestCommonSubpath(int n, vector<vector<int>>& paths) {
    //     vector<ull> p(n+2,1); 
    //     vector<vector<ull>> hsh(paths.size());
    //     ull P=100001, mod=1000000009, mn=100005;
    //     for(int i=0; i<=n; i++){ p[i+1]=(1LL*p[i]*P)%mod; }
    //     for(int i=0; i<paths.size(); i++){
    //         mn=min(mn,(ull)paths[i].size());
    //         hsh[i].resize(paths[i].size()+1,0);
    //         for(int j=0; j<paths[i].size(); j++){
    //             hsh[i][j+1]=((1LL*hsh[i][j]*P+paths[i][j])%mod);
    //         }
    //     }
    //     int low=1, high=(int)mn, ans=0;
    //     while(low<=high){
    //         int len=(low+high+1)/2;
    //         unordered_map<ull,vector<int>> seen;
    //         cout<<len<<endl;
    //         for(int i=0; i+len<=paths[0].size(); i++){
    //             ull curr=(hsh[0][i+len]+mod-hsh[0][i]*p[len])%mod;
    //             seen[curr].push_back(i);
    //             cout<<curr<<' ';
    //         }
    //         cout<<endl;
    //         for(int k=1; k<paths.size(); k++){
    //             cout<<k<<"->"<<seen.size()<<' ';
    //             // if(seen.empty()){ break; }
    //             unordered_map<ull,vector<int>> temp;
    //             for(int i=0; i+len<=paths[k].size(); i++){
    //                 ull curr=(hsh[k][i+len]-hsh[k][i]*p[len]+mod)%mod;
    //                 cout<<curr<<' ';
    //                 if(!seen.count(curr)){ continue; }
    //                 for(auto j:seen[curr]){
    //                     if(equal(paths[0].begin()+j, paths[0].begin()+j+len, paths[k].begin()+i, paths[k].begin()+i+len)){
    //                         temp[curr].push_back(i);
    //                         break;
    //                     }
    //                 }
    //             }
    //             cout<<endl;
    //             if(temp.size()==0){ break; }
    //             seen=temp;
    //         }
    //         if(seen.empty()){ high=len-1; }
    //         else{ ans=len; low=len+1; }
    //         cout<<endl;
    //     }
    //     return ans;
    // }
    int longestCommonSubpath(int n, vector<vector<int>>& ps) {
    int l = 0, r = min_element(begin(ps), end(ps), [](const auto& a, const auto &b){ return a.size() < b.size(); })->size();
    int base = 100001, mod = 1000000007;
    while (l < r) {
        int m = (l + r + 1) / 2;
        unordered_map<int, vector<int>> hs;
        for (int i = 0; i < ps.size() && (i == 0 || !hs.empty()); ++i) {
            long long hash = 0, d = 1;
            unordered_map<int, vector<int>> hs1;
            for (int j = 0; j < ps[i].size(); ++j) {
                hash = (hash * base + ps[i][j]) % mod;
                if (j >= m)
                    hash = (mod + hash - d * ps[i][j - m] % mod) % mod;
                else
                    d = d * base % mod;    
                if (j >= m - 1) {
                    if (i == 0)
                        hs1[hash].push_back(j + 1 - m);
                    else
                        if (hs.count(hash))
                            for (auto pos : hs[hash])
                                if (equal(begin(ps[0]) + pos, begin(ps[0]) + pos + m, begin(ps[i]) + j + 1 - m)) {
                                    hs1[hash].push_back(pos);
                                    break;
                                }
                }
            }
            swap(hs, hs1);
        }
        if (hs.empty()) r = m - 1;
        else l = m;            
    }
    return l;
}
};