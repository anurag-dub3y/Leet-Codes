class DSU{
public:
    map<string,string> p;
    map<string,long long> sz;
    bool compare(string s, string t){
        int cnt=0;
        for(int i=0; i<s.length(); i++){ cnt+=s[i]!=t[i]; }
        return cnt==2 and findPar(s)!=findPar(t);
    }
    string findPar(string s){
        if(p[s]==s){ return s; }
        return p[s]=findPar(p[s]);
    }
    void join(string s, string t){
        s=findPar(s), t=findPar(t);
        if(sz[s]>=sz[t]){
            p[t]=s; sz[s]+=sz[t];
        }
        else{
            p[s]=t; sz[t]+=sz[s];
        }
    }
};
class Solution {
public:
    DSU D;
    int numSimilarGroups(vector<string>& strs) {
        set<string> s(begin(strs),end(strs));
        vector<string> v(begin(s),end(s));
        for(int i=0; i<v.size(); i++){
            D.p[v[i]]=v[i];
            D.sz[v[i]]=1;
        }
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if(D.compare(v[i],v[j])){ D.join(v[i],v[j]); }
            }
        }
        int ans=0;
        for(auto it:v){
            if(D.p[it]==it){ ans++; }
        }
        return ans;
    }
};