class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        int n=friends.size();
        vector<int> vis(n,0);
        vis[id]=1;
        q.push(id);
        unordered_map<string,int> freq;
        vector<int> inds;
        while(!q.empty()){
            if(level==0){
                while(!q.empty()){
                    inds.push_back(q.front()); q.pop();
                }
                break;
            }
            int sz=q.size(); 
            while(sz--){
                int i=q.front(); q.pop();
                for(int j:friends[i]){
                    if(!vis[j]){ q.push(j); vis[j]=1; }
                }
            }
            level--;
        }
        for(auto &i:inds){
            for(auto &j:watchedVideos[i]){ freq[j]++; }
        }
        vector<string> ans;
        vector<pair<int,string>> vp;
        for(auto &[s,cnt]:freq){ vp.push_back({cnt,s}); }
        sort(begin(vp),end(vp));
        for(auto &[cnt,s]:vp){ ans.push_back(s); }
        return ans;
    }
};