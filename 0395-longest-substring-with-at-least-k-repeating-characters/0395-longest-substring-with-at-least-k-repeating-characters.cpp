class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> st(begin(s),end(s));
        int total=st.size();
        int ans=0;
        for(int curr=1; curr<=total; curr++){
            int st=0, end=0, tmp[26]={0}, uniq=0, good=0;
            while(end<s.length()){
                // cout<<st<<' '<<end<<' '<<uniq<<' '<<good<<endl;
                if(uniq<=curr){
                    if(tmp[s[end]-'a']==0){ uniq++; }
                    tmp[s[end]-'a']++;
                    if(tmp[s[end]-'a']==k){ good++; }
                    end++;
                }
                else{
                    if(tmp[s[st]-'a']==k){ good--; }
                    tmp[s[st]-'a']--;
                    if(tmp[s[st]-'a']==0){ uniq--; }
                    st++;
                }
                if(uniq==curr and good==uniq){ ans=max(ans,end-st); }
            }
        }
        return ans;
    }
};