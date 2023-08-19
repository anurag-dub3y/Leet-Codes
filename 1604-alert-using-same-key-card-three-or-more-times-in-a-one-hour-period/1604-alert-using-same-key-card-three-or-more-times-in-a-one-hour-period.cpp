class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        auto diff=[&](string s2, string s1){
            int t1=0, t2=0;
            for(int i=0; i<s1.length(); i++){
                if(s1[i]==':'){ t1*=60; }
                else{ t1*=10; t1+=(s1[i]-'0');  }
            }
            for(int i=0; i<s2.length(); i++){
                if(s2[i]==':'){ t2*=60; }
                else{ t2*=10; t2+=(s2[i]-'0');  }
            }
            // cout<<s1<<' '<<s2<<' '<<' ';
            // cout<<t2<<' '<<t1<<' '<<t2-t1<<endl;
            return t2-t1<=6000;
        };
        map<string,vector<string>> m;
        for(int i=0; i<keyName.size(); i++){
            m[keyName[i]].push_back(keyTime[i]);
        }
        vector<string> ans;
        for(auto &[name,it]:m){
            if(it.size()<3){ continue; }
            sort(begin(it),end(it));
            for(int i=2; i<it.size(); i++){
                if(diff(it[i],it[i-2])){ ans.push_back(name); break; }
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};