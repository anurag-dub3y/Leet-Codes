class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.length();
        if(s[0]==' ' or s[n-1]==' ' or (s[0]!=s[n-1])){ return false; }
        int ind=-1;
        for(int i=1; i<n-1; i++){
            if(s[i]==' '){
                ind=i;
                if(s[i-1]!=s[i+1]){ return false; }
            }
        }
        return true;
    }
};