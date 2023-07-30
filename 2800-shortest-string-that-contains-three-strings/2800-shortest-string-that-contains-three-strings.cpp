class Solution {
    bool findIfPresent(string &big, string &small){
        // if(big.length()<small.length()){ return findIfPresent(small,big); }
        for(int i=0; i+small.length()<=big.length(); i++){
            if(big.substr(i,small.length())==small){ return true; }
        }
        return false;
    }
    string joint(string &s1, string &s2){
        string ans=s1+s2;
        int common=0;
        for(int len=1; len<=min(s1.length(),s2.length()); len++){
            string suff=s1.substr(s1.length()-len), pref=s2.substr(0,len);
            if(pref==suff){ common=len; }
        }
        if(common){ return s1+s2.substr(common); }
        return ans;
    }
public:
    string minimumString(string a, string b, string c) {
        if(findIfPresent(a,b)){ return minimumString(a,c); }
        else if(findIfPresent(b,a)){ return minimumString(b,c); }
        else if(findIfPresent(a,c)){ return minimumString(a,b); }
        else if(findIfPresent(c,a)){ return minimumString(c,b); }
        else if(findIfPresent(b,c)){ return minimumString(b,a); }
        else if(findIfPresent(c,b)){ return minimumString(c,a); }
        
        
        string s1=joint(a,b), s2=joint(b,a), s3=joint(b,c), s4=joint(c,b), s5=joint(c,a), s6=joint(a,c);
        
        // cout<<s1<<' '<<s2<<' '<<s3<<' '<<s4<<' '<<s5<<' '<<s6<<endl;
        
        // a b + c, a + b c
        // a c + b, a + c b
        // b a + c, b + a c
        // b c + a, b + c a
        // c a + b, c + a b
        // c b + a, c + b a
        
        vector<string> s(12);
        s[0]=joint(s1,c), s[1]=joint(a,s3);
        s[2]=joint(s6,b), s[3]=joint(a,s4);
        s[4]=joint(s2,c), s[5]=joint(b,s6);
        s[6]=joint(s3,a), s[7]=joint(b,s5);
        s[8]=joint(s5,b), s[9]=joint(c,s1);
        s[10]=joint(s4,a), s[11]=joint(c,s2);
        
        sort(begin(s),end(s),[&](string &x, string &y){
            if(x.length()!=y.length()){ return x.length()<y.length(); }
            return x<y;
        });
        
        return s[0];
    }
    
    string minimumString(string a, string b) {
        if(findIfPresent(a,b)){ return a; }
        else if(findIfPresent(b,a)){ return b; }
        
        vector<string> s(2);
        s[0]=joint(a,b), s[1]=joint(b,a);
        
        sort(begin(s),end(s),[&](string &x, string &y){
            if(x.length()!=y.length()){ return x.length()<y.length(); }
        return x<y;
        });
        
        return s[0];
    }
    
};