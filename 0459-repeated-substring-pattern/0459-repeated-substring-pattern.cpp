class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1; i<=s.length()/2; i++){
            string tmp=s.substr(0,i);
            string tmp2=s.substr(i);
            // cout<<tmp<<' '<<tmp2<<endl;
            if(check(tmp,tmp2)){ return true; }
        }
        return false;
    }
    bool check(string &tmp, string &s){
        if(s.length()==0 or tmp==s){ return true; }
        if(s.length()<tmp.length()){ return false; }
        int n=tmp.length();
        string tmp2=s.substr(n);
        return s.substr(0,n)==tmp and check(tmp,tmp2);
    }
};