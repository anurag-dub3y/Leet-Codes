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
    
    Trie() {
        root=new node();
    }
    
    ~Trie(){
        clear(root);
    }
    
    void clear(node* root){
        for(int i=0;i<26;i++){
            if(root->next[i]){ clear(root->next[i]); }
        }
        delete root;
    }
    
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
    
    bool search(string word, bool isSearch=true) {
        node* dummy=root;
        for(char c:word){
            if(!dummy->next[c-'a']){ return false; }
            dummy=dummy->next[c-'a'];
        }
        if(isSearch){
            return dummy and dummy->is_end==true;
        }
        return dummy;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */