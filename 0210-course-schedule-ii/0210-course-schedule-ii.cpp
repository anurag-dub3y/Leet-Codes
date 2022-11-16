class Solution {
public:
    vector<int> g[2001];
    vector<int> vis;
    stack<int> s;
    void dfs(int i){
        vis[i]=1;
        for(auto j:g[i]){
            if(!vis[j]){ dfs(j); }
        }
        s.push(i);
    }
    vector<int> x(int numCourses){
        vector<int> ans;
        for(int i=0; i<numCourses; i++){ ans.push_back(i); }
        return ans;
    }
    bool dfs2(int i, vector<int> &vis2, vector<int> &order){
        vis2[i]=1;
        order[i]=1;
        for(auto j:g[i]){
            if(!vis2[j]){ if(dfs2(j,vis2,order)){ return true; } }
            else if(order[j]==1){ return true; }
        }
        order[i]=0;
        return false;
    }
    bool courses1(int n){
        vector<int> vis(n+1,0), order(n+1,0);
        for(int i=0; i<=n; i++){
            if(!vis[i]){
                if(dfs2(i,vis,order)){ return false; }
            }
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        if(p.size()==0){ return x(numCourses); }
        vis.resize(2001,0);
        for(auto j:p){
            g[j[1]].push_back(j[0]);
        }
        if(!courses1(numCourses)){ return {}; }
        for(int i=0; i<numCourses; i++){
            if(!vis[i] and g[i].size()){ dfs(i); }
        }
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){ s.push(i); }
        }
        vector<int> ans;
        while(!s.empty()){ ans.push_back(s.top()); s.pop(); }
        return ans;
    }
};