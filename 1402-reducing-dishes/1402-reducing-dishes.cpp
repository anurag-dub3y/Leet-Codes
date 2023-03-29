class Solution {
public:
    // map<vector<int>,int> m;
    map<pair<int,int>,int> m;
    int run(int ind, int order, int curr, vector<int>& st){
        if(ind==st.size()){ return curr; }
        if(m.count({ind,order})){ return m[{ind,order}]; }
        // if(m.count({ind,order,curr})){ return m[{ind,order,curr}]; }
        int v1=run(ind+1,order,curr,st);
        int v2=run(ind+1,order+1,curr+st[ind]*order,st);
        // return m[{ind,order,curr}]=max(v1,v2);
        return m[{ind,order}]=max(v1,v2);
    }
    int maxSatisfaction(vector<int>& st) {
        sort(begin(st),end(st));
        return run(0,1,0,st);
    }
};