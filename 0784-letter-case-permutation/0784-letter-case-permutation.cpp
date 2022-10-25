class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.length(); 
        int cnt=0; 
        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){ cnt++; } 
            else if(s[i]>='A' && s[i]<='z'){ cnt++; } 
        }
        
        vector<string> ans; 
        int x=0;
        for(int i = 0; i <(1<<cnt); i++){
            string curr="";
            for(int j=0, p=0; j<n; j++){
                if((s[j] >= 'a' && s[j] <= 'z') or (s[j] >= 'A' && s[j] <= 'Z')){
                    if(x&(1 << p++)){ curr += toupper(s[j]); } 
                    else{ curr += tolower(s[j]); } 
                }
                else{ curr += s[j];  }
            }
            ans.push_back(curr);
            x++;
        }
        return ans;
    }
};

