class Solution {
public:
    void tpSort(vector<vector<int>> &g, vector<int> &indegree, vector<int> &visited){
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){ q.push(i); }
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            visited.push_back(node);
            for(auto v : g[node]) {
                if(--indegree[v] == 0){ q.push(v); }
            }
        }
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {   
        int group_id = m;
        
        // Ungrouped items are in individual groups
        for(int i = 0; i < n; i++) {
            if(group[i] == -1){ group[i] = group_id++; }
        }
        
        vector<int> item_indegree(n, 0);
        vector<vector<int>> item_graph(n);
        
        vector<int> group_indegree(group_id, 0);
        vector<vector<int>> group_graph(group_id);        
        
        for(int curr = 0; curr < n; curr++){
            for(int prev : beforeItems[curr]) {
                
                // Directed edge from prev to current item
                item_graph[prev].push_back(curr);
                item_indegree[curr]++;
                
                // If prev and curr are of different groups, add an edge 
                // from prev to curr
                if(group[prev] != group[curr]){
                    group_graph[group[prev]].push_back(group[curr]);
                    group_indegree[group[curr]]++;
                }
            }
        }
        
        // This stores the order in which items/groups are visited chronologically
        vector<int> visited_items;
        vector<int> visited_groups;
        
        tpSort(item_graph, item_indegree, visited_items);
        tpSort(group_graph, group_indegree, visited_groups);
        
        if(visited_items.size() != n or visited_groups.size() != group_id ){ return {}; }
        
        vector<int> ans;
        unordered_map<int, vector<int>> umap;

        // Grouping together items of the same group, in order
        for(auto elem : visited_items){ umap[group[elem]].push_back(elem); }
        
        // Inserting ordered items from ordered groups
        for(auto gp_elem : visited_groups){
            ans.insert(ans.end(), umap[gp_elem].begin(), umap[gp_elem].end());
        }
        
        return ans;
    }
};