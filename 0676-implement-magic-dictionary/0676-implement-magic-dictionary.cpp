class MagicDictionary {
public:
    set<string> d;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &s:dictionary){
            d.insert(s);
        }
    }
    
    bool search(string s) {
        for(int i=0; i<s.length(); i++){
            for(char c='a'; c<='z'; c++){
                if(c==s[i]){ continue; }
                string tmp=s; tmp[i]=c;
                if(d.count(tmp)){ return true; }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */