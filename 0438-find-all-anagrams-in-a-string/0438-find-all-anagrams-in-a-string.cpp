class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.length(), n=s.length();
        vector<int> ans;
        if(n<k){ return ans; }
        vector<int> curr(26,0), freq(26,0);
        int i=0, j=0;
        while(i<k){
            curr[s[i]-'a']++; freq[p[i]-'a']++;
            i++;
        }
        i--;
        while(i<n){
            if(curr==freq){ ans.push_back(j); }
            i++;
            if(i<n){ curr[s[i]-'a']++; }
            curr[s[j++]-'a']--;
        }
        return ans;
    }
};