class LockingTree {
public:
    
    unordered_map<int,int> locks_aquired;
    vector<vector<int>> graph;
    unordered_map<int,int> parents;
    
    LockingTree(vector<int>& parent) {   
        int n=parent.size();
        graph =  vector<vector<int>>(n);
        parents[0] = -1 ;   
        for(int i=1; i<n; i++) {
            parents[i] = parent[i];  
            graph[parent[i]].push_back(i);
        }
    }
     
    bool lock(int num, int user) {
        if(locks_aquired.find(num) == locks_aquired.end()){ locks_aquired[num]=user; return 1;}
        return 0;
    }
    
    
    bool unlock(int num, int user) {
        if(locks_aquired.find(num)!=locks_aquired.end() and locks_aquired[num]==user) { 
            locks_aquired.erase(num); 
            return 1;
        }
        return 0;
    }
    
    bool check_ans(int num) {
        while(num != -1) {
            if(locks_aquired.find(num) != locks_aquired.end()){ return 0; }
            num = parents[num];   
        }
        return 1;
    }
    
    bool dfs(int num) {
        for(int i=0; i<graph[num].size(); i++) {
            int x = graph[num][i]; 
            if(locks_aquired.find(x) != locks_aquired.end()){ return 1; }
            if(dfs(x)){ return 1; }
        }
        return 0; 
    }
    
    void unlock_descendents(int num) {
        for(int i=0; i<graph[num].size(); i++){
            int x = graph[num][i]; 
            if(locks_aquired.find(x) != locks_aquired.end()){ locks_aquired.erase(x); }
            unlock_descendents(x);
        }
    }
    
    bool upgrade(int num, int user) {   
        if(locks_aquired.find(num)!=locks_aquired.end()){ return 0; }
        if(dfs(num) and check_ans(parents[num])){
            unlock_descendents(num); 
            locks_aquired[num]=user;
            return 1;
        }
        return 0;
    }
};