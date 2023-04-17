class Solution {
public:
    int addMinimum(string word) {
        int ans=(word[0]=='b'?1:word[0]=='c'?2:0);
        for(int i=1; i<word.length(); i++){
            if(word[i]=='b'){
                if(word[i-1]=='c'){ ans++; }
                else if(word[i-1]=='b'){ ans+=2; }
            }
            if(word[i]=='c'){
                if(word[i-1]=='a'){ ans++; }
                else if(word[i-1]=='c'){ ans+=2; }
            }
            if(word[i]=='a'){
                if(word[i-1]=='b'){ ans++; }
                else if(word[i-1]=='a'){ ans+=2; }
            }
        }
        if(word.back()=='a'){ ans+=2; }
        if(word.back()=='b'){ ans+=1; }
        return ans;
    }
};