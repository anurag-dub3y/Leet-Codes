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
    
    bool search(node* dummy, string word, int ind) {
        if(ind==word.size()){ return dummy->is_end; }        
        char c=word[ind];
        if(c!='.'){
            if(!dummy->next[c-'a']){ return false; }
            return search(dummy->next[c-'a'],word,ind+1);
        }
        for(int i=0; i<26; i++){
            if(dummy->next[i]){
                if(search(dummy->next[i],word,ind+1)){ return true; }
            }
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie *T = new Trie();
    node *root=T->root;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        T->insert(word);
        // cout<<"Adding "<<word<<'\n';
    }
    
    bool search(string word) {
        node *dummy=T->root;
        bool x=T->search(dummy,word,0);
        // cout<<"Searching "<<word<<' '<<x<<'\n';
        return x;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */