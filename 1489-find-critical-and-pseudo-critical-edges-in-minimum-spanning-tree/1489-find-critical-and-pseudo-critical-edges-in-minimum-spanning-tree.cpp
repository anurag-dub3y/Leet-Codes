class UF{
public:
    vector<int> par, sz;
    UF(int n){
        par.resize(n);
        for(int i=0; i<n; i++){ par[i]=i; }
        sz=vector<int>(n,1);
    }
    int findPar(int n){
        if(par[n]==n){ return n; }
        return par[n]=findPar(par[n]);
    }
    void merge(int a, int b){
        a=findPar(a);
        b=findPar(b);
        if(sz[a]>sz[b]){ par[b]=a; sz[a]+=sz[b]; }
        else{ par[a]=b; sz[b]+=sz[a]; }
    }
};
class Solution {
public:
    int MST(vector<vector<int>>& edges, int blocked, int currEdge, int n){
        UF U(n);
        int weight=0;
        if(currEdge!=-1){
            weight+=edges[currEdge][2];
            U.merge(edges[currEdge][0],edges[currEdge][1]);
        }
        for(int i=0; i<edges.size(); i++){
            if(i==blocked or U.findPar(edges[i][0])==U.findPar(edges[i][1])){ continue; }
            weight+=edges[i][2];
            U.merge(edges[i][0],edges[i][1]);
        }
        for(int i=0; i<n; i++){
            if(U.findPar(i)!=U.findPar(0)){ return INT_MAX; }
        }
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++){ edges[i].push_back(i); }
        sort(begin(edges),end(edges),[&](const vector<int> &a, const vector<int> &b){
            return a[2]<b[2]; 
        });
        int mstWeight=MST(edges,-1,-1,n);
        vector<int> critical, pseudoCritical;
        for(int i=0; i<edges.size(); i++){
            int v1=MST(edges,i,-1,n), v2=MST(edges,-1,i,n);
            if(v1>mstWeight){ critical.push_back(edges[i][3]); }
            else if(v2==mstWeight){ pseudoCritical.push_back(edges[i][3]); }
        }
        return {critical,pseudoCritical};
    }
};

