class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0; i<26; i++){
            mp[order[i]]=i;
        }
        vector<string> srt = words;
        sort(begin(srt),end(srt),[&](const string &a, const string &b){
            for(int i=0; i<min((int)a.size(),(int)b.size()); i++){
                if(mp[a[i]]<mp[b[i]]){ return true; }
                else if((mp[a[i]]>mp[b[i]])){ return false; }
            }
            if(a.size()<=b.size())return true;
            return false;
        }); 
        return srt==words;
    }
};