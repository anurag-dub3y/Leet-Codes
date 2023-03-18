class node {
    public:
    node *next[26];
    bool is_end;
    node(bool x=false){
        memset(next,0,sizeof(next));
        is_end=x;
    }
};
class Trie {
public:
    node *root;
    Trie() { root=new node(); }
    
    void insert(string word) {
        node *p=root;
        for(int i=0; i<word.length(); i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a']=new node();
            }
            p=p->next[word[i]-'a'];
        }
        p->is_end=true;
    }
    
    bool search(string word) {
        node* dummy=root;
        for(char c:word){
            if(!dummy->next[c-'a']){ return false; }
            dummy=dummy->next[c-'a'];
        }
        return dummy and dummy->is_end==true;
    }
};

class Solution {
public:
    
    Trie *T=new Trie();
    node *root=T->root;
    
    vector<string> ans;
    vector<string> find(string s, bool &canFind){
        int n=s.length();
        if(n==0){ canFind=true; return {}; }
        vector<string> ans;
        string res="";
        for(int i=1; i<=n; i++){
            res=s.substr(0,i);
            if(T->search(res)){
                // cout<<res<<' ';
                bool t=false;
                string temp=res;
                vector<string> x=find(s.substr(i),t);
                if(t){ 
                    canFind=true;
                    if(x.size()==0){ ans.push_back(temp); }
                    else{
                        for(auto it:x){
                            ans.push_back(temp+' '+it); 
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &it:wordDict){ T->insert(it); }
        bool canFind=false;
        return find(s,canFind);
    }
};