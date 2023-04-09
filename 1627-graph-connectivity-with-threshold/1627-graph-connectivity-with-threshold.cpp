class Solution {
public:
    vector<int> parent, rank;
    void make_set(int &v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int &v) {
        if (v == parent[v]){ return v; }
        return parent[v] = find_set(parent[parent[v]]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]){ swap(a, b); }
            parent[b] = a;
            if (rank[a] == rank[b]){ rank[a]++; }
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n+1); rank.resize(n+1);
        for(int i=1; i<=n; i++){ make_set(i); }
        for(int i=threshold+1; i<=n; i++) {
            int j=1;
            while(i*j<=n){
                union_sets(i,i*j);
                j++;
            }
        }
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int a=queries[i][0], b=queries[i][1];
            if(find_set(a)==find_set(b)){ ans[i]=true; }
            else{ ans[i]=false; }
        }
        return ans;
    }
};