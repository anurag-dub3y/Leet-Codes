class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> v;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){ v.push_back(i); }
        }
        string ans="";
        int vis=0;
        for(int i=0; i<s.length(); i++){
            if(vis+k-1>=v.size()){ break; }
            int ind=v[vis+k-1];
            if(vis<v.size() and v[vis]==i){ vis++; }
            string tmp=s.substr(i,ind-i+1);
            if(ans.length()==0 or tmp.length()<ans.length() or (tmp.length()==ans.length() and tmp<ans)){ ans=tmp; }
            // cout<<tmp<<' ';
            // cout<<i<<' '<<ind<<' '<<tmp<<endl;
        }
        return ans[0]=='0'?"":ans;
    }
};