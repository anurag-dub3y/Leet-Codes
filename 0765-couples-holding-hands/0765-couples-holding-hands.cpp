class Solution {
public:
    vector<int> p;
    int findPar(int n){
        if(p[n]==n){ return n; }
        return n=findPar(p[n]);
    }
    void join(int a, int b){
        a=findPar(a), b=findPar(b);
        p[a]=b;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        p.resize(n+1);
        for(int i=0; i<n; i++){ p[i]=i; }
        for(int i=0; i<n; i+=2){ join(i,i+1); }
        int ans=0;
        for(int i=0; i<n; i+=2){
            int a=findPar(row[i]), b=findPar(row[i+1]);
            if(a!=b){
                ans++;
                join(a,b);
            }
        }
        return ans;
    }
};


// 0 2 1 3