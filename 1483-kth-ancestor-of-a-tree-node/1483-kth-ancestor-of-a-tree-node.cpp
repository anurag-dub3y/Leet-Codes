class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n,vector<int>(20,-1));
        for(int i=0; i<n; i++){ dp[i][0]=parent[i]; }   // (1<<0)th = first parent
        for(int j=1; j<20; j++){
            for(int i=0; i<n; i++){
                int prevAncestor=dp[i][j-1];
                if(prevAncestor!=-1){ dp[i][j]=dp[prevAncestor][j-1]; }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = dp[node][i];
                if (node == -1){ return -1; }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */