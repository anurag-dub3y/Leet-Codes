class Solution {
public:
    using vii=vector<int>;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
//         map<int,vector<int>> mp;
//         for(int i=0; i<p.size(); i++){
//             mp[p[i][0]].push_back(p[i][1]);
//         }
//         for(auto &i:m){ sort(begin(i.second),end(i.second)); }
//         vector<vector<int>> ans;
//         int shortest=0;
//         map<int,int> taken;
//         for(auto it:m){
            
//         }
        sort(begin(p),end(p),[&](const vii &a, const vii &b){
            return a[0]!=b[0]?a[0]>b[0]:a[1]<b[1];  
        });
//         map<pair<int,int>,int> vis;
//         vis[{p[0][0],p[0][1]}]=p[0][1]; // First one has a fixed position
//         int takenThisTime=0;
//         for(auto v:p){
//             if(!vis[{v[0],v[1]}]){
                
//             }
//         }
        vector<vector<int>> ans;
        for(int i = 0; i < p.size(); i++){
            ans.insert(ans.begin()+p[i][1], p[i]);
        }
        return ans;
    }
};