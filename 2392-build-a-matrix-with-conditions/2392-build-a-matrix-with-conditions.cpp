class Solution {
public:
    bool isCyclicUtil(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;
    
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, graph, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    
        recStack[node] = false;
        return false;
    }
    
    bool hasCycle(vector<vector<int>>& graph, int nodes) {
        vector<bool> visited(nodes, false);
        vector<bool> recStack(nodes, false);
    
        for (int i = 0; i < nodes; ++i) {
            if (!visited[i]) {
                if (isCyclicUtil(i, graph, visited, recStack)) {
                    return true;
                }
            }
        }
    
        return false;
    }
    
    void topologicalSortUtil(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& result) {
        visited[node] = true;
    
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, graph, visited, result);
            }
        }
    
        result.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& graph, int nodes) {
        vector<bool> visited(nodes, false);
        stack<int> result;
    
        for (int i = 0; i < nodes; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, graph, visited, result);
            }
        }
    
        vector<int> sortedNodes;
        while (!result.empty()) {
            sortedNodes.push_back(result.top());
            result.pop();
        }
    
        return sortedNodes;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Make two graphs, one for row and one for col
        // Check for cycles, if found return {}
        // TP Sort both
        // We now have row number and col number
        vector<vector<int>> row(k);
        vector<vector<int>> col(k);
        for(auto &r:rowConditions){
            row[r[0]-1].push_back(r[1]-1);
        }
        for(auto &c:colConditions){
            col[c[0]-1].push_back(c[1]-1);
        }
        
        if(hasCycle(row,k) or hasCycle(col,k)){ return {}; }
        vector<int> rows=topologicalSort(row,k);
        vector<int> cols=topologicalSort(col,k);
        vector<vector<int>> ans(k,vector<int>(k,0));
        unordered_map<int,int> rowNumber;
        for(int i=0; i<k; i++){ rowNumber[rows[i]]=i; }
        for(int i=0; i<k; i++){
            ans[rowNumber[cols[i]]][i]=1+cols[i];
        }
        return ans;
    }
};