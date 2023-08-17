class Solution {
public:
    bool visited[100005] = {};
    int dfs(int i, vector<vector<int>> &al) {
        visited[i] = true;
        int ans=0;
        return 1 + accumulate(begin(al[i]), end(al[i]), 0, [&](int res, int j){
            return max(res, dfs(j, al));
        });
    }
    int maximumInvitations(vector<int>& fav) {
        int res = 0;
        vector<vector<int>> al(fav.size());
        for(int i = 0; i < fav.size(); ++i){
            if (fav[fav[i]] != i){
                al[fav[i]].push_back(i);
            }
        
        }
        // Mutual liking, will make a crab
        for(int i = 0; i < fav.size(); ++i){
            if (fav[fav[i]] == i){
                res += dfs(i, al);
            }
        }
        
        // Length of longest cycle
        for(int i = 0; i < fav.size(); ++i) {
            int cnt = 0, j = i;
            for (; visited[j] == false; j = fav[j]) {
                visited[j] = true;
                ++cnt;
            }
            for (int k = i; k != j; k = fav[k]){ --cnt; }
            res = max(res, cnt); 
        }
        
        return res;
    }
};