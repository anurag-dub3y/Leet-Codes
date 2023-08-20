class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> vp;
        vp.push_back(1);
        for(int i=1; i<n; i++){
            int r=vp.back()+1;
            while(find(begin(vp),end(vp),k-r)!=vp.end()){ r++; }
            vp.push_back(r);
        }
        // for(auto &i:vp){ cout<<i<<' '; } cout<<endl;
        return accumulate(begin(vp),end(vp),0);
    }
};
