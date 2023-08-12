class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> mp(n+1,0);
        for(auto &e:edges){
            mp[e[0]]++;
            mp[e[1]]++;
            if(mp[e[0]]>=(n+1)/2){ return e[0]; }
            if(mp[e[1]]>=(n+1)/2){ return e[1]; }
        }
        return -1;
    }
};