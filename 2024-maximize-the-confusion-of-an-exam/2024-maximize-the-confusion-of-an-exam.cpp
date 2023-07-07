class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.length();
        int i=0, j=0, ans=0, f=0;
        while(i<n){
            if(s[i]=='F'){ f++; }
            while(f>k){
                if(s[j]=='F'){ f--; }
                j++;
            }
            if(f<=k){ ans=max(ans,i-j+1); }
            i++;
        }
        int t=0; i=0, j=0;
        while(i<n){
            if(s[i]=='T'){ t++; }
            while(t>k){
                if(s[j]=='T'){ t--; }
                j++;
            }
            if(t<=k){ ans=max(ans,i-j+1); }
            i++;
        }
        return ans;
    }
};