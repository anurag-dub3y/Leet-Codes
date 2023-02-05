class Solution {
public:
    bool f(string &x){
        string s="aeiou";
        return count(s.begin(),s.end(),x[0])!=0 and count(s.begin(),s.end(),x.back())!=0;
    }
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& qq) {
        int n=w.size();
        vector<int> p(n+1,0);
        for(int i=1; i<=n; i++){
            p[i]=p[i-1]+(f(w[i-1]));
        }
        vector<int> ans;
        for(auto q:qq){
            int r=p[q[1]+1], l=p[q[0]];
            ans.push_back(r-l);
        }
        return ans;
    }
};