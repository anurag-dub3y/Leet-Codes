class Solution {
public:
    long long maximumSubsequenceCount(string text, string pat) {
        long long ans1=0, ans2=0;
        int m=1;
        for(int i=0;i<text.size();i++){
            if(pat[1]==text[i]){ ans1+=m; }
            if(pat[0]==text[i]){ m++; }
        }
        int p=1;
        for(int i=text.size()-1;i>=0;i--){
             if(pat[0]==text[i]){ ans2+=p; }
            if(pat[1]==text[i]){ p++; }
        }
        return max(ans1,ans2);
        
    }
};