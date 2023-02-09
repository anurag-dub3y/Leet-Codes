class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>> m;
        long long ans=0;
        for(auto i:ideas){
            string f=i.substr(1);
            m[i[0]].insert(f);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            for(auto jt=next(it); jt!=m.end(); jt++){
                // if(it==jt){ continue; }
                auto s1=it->second, s2=jt->second;
                int f1=0, f2=0;
                for(auto i:s1){ if(s2.count(i)==0){ ++f1; } }
                for(auto i:s2){ if(s1.count(i)==0){ ++f2; } }
                ans+=2*f1*f2;
                // cout<<i+it.first<<' '<<i<<' '<<ans<<'\n';
                // cout<<it.first<<' '<<ans<<'\n';
            }
        }
        return ans;
    }
};