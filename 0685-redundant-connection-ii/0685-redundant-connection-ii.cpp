/* 
There are two cases for the tree structure to be invalid.
1) A node having two parents, including corner case: e.g. [[4,2],[1,5],[5,2],[5,3],[2,4]]
2) A cycle exists

If we can remove exactly 1 edge to achieve the tree structure, a single node can have at most two parents. 

1) Check whether there is a node having two parents. 
    If so, store them as candidates A and B, and set the second edge invalid. 
2) Perform normal union find. 
    If the tree is now valid 
           simply return candidate B
    else if candidates not existing 
           we find a circle, return current edge; 
    else 
           remove candidate A instead of B.
*/

class Solution {
public:
    vector<int> par;
    int Find(int x) {
        if (par[x] < 0) return x;
        return par[x] = Find(par[x]);
    }
    
    bool Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx == ry) return 1;
        if (par[rx] > par[ry]) {
            swap(rx, ry);
        }
        par[rx] += par[ry];
        par[ry] = rx;
        return 0;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int a, b, v = -1;
        par=vector<int>(edges.size()+1,0);
        for (auto &e : edges) {
            if (par[e[1]]) {
                a = par[e[1]];
                b = e[0];
                v = e[1];   // v has two incoming edges
                break;
            }
            par[e[1]] = e[0];
        }
        
        par.assign(edges.size()+1, -1);
        
        if (v == -1) {
            // to detect a cycle
            for (auto &e : edges) {
                if (Union(e[0], e[1])) { return e; }
            }
        } 
        else {
            for (auto &e : edges) {
                if (e[0] == b){ continue; }
                if (Union(e[0], e[1])) { return {a, v}; }
            }
            return {b, v};
        }
        return {};
    }
};