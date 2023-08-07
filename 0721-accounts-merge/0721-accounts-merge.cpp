class Solution {
public:
    map<string,string> par;
    map<string,int> name;
    map<string,long long> sz;
    string findPar(string s){
        if(par[s]==s){ return s; }
        return par[s]=findPar(par[s]);
    }
    void merge(string s1, string s2){
        s1=findPar(s1), s2=findPar(s2);
        if(s1==s2){ return; }
        if(sz[s1]<sz[s2]){ swap(s1,s2); }
        par[s2]=s1; 
        sz[s1]+=sz[s2];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        for(int j=0; j<accounts.size(); j++){
            vector<string> a=accounts[j];
            for(int i=1; i<a.size(); i++){
                par[a[i]]=a[i]; 
                sz[a[i]]=1;
                name[a[i]]=j;
            }
        }
        for(auto &a:accounts){
            for(int i=2; i<a.size(); i++){
                merge(a[i],a[i-1]);
            }
        }
        map<string,vector<string>> accs;
        for(auto &[s,p]:par){ accs[findPar(p)].push_back(s); }
        for(auto &[parentString,it]:accs){
            vector<string> tmp={accounts[name[parentString]][0]};
            for(auto &i:it){ tmp.push_back(i); }
            ans.push_back(tmp);
        }
        return ans;
    }
};