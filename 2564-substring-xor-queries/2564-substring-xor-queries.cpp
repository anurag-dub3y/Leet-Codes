class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,pair<int,int>> u;
        for(int i=0; i<s.length(); i++){
            int x=0;
            for(int j=i; j<min((int)(i+31),(int)s.length()); j++){
                x*=2; x+=(s[j]-'0'); 
                if(u.find(x)==u.end()){ u[x]={i,j}; }
                if(s[i]=='0'){ break; }
            }
        }
        vector<vector<int>> ans;
        for(auto q:queries){
            int x=q[0]^q[1];
            if(u.find(x)==u.end()){ ans.push_back({-1,-1}); }
            else{ ans.push_back({u[x].first,u[x].second}); }
        }
        return ans;
    }
};