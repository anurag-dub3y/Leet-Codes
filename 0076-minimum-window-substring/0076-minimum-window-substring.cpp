class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length();
        if(m<n or !m or !n){ return ""; }
        vector<int> freq(256,0);
        for(auto i:t){ freq[i]++; }
        int cntRemaining=n;
        int i=0, j=0, minLen=INT_MAX, lastInd=0; string ans="";
        while(i<=m && j<m){
            if(cntRemaining){
                if(i==m){ break; }
                freq[s[i]]--;
                if(freq[s[i]]>=0){ cntRemaining--; }
                i++;
            }
            else{
                if(i-j<minLen){
                    minLen=i-j;
                    lastInd=j;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0){ cntRemaining++; }
                j++; 
            }
        }
        return minLen==INT_MAX?"":s.substr(lastInd,minLen);
    }
};