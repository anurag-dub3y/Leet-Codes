class node{
    public:
        unordered_map<int,node*> next;
        // node *next[27];
        int last;
        node(){
            // memset(next,0,sizeof(next));
            next.clear();
            last=-1;
        }
};
class trie{
    public:
    node *root=new node();
    void insert(string &word, int i){
        node *temp=root;
        for(auto c:word){
            if(temp->next.count(c-'a')==0){
                temp->next[c-'a']=new node();
            }
            temp=temp->next[c-'a'];
            temp->last=i;
        }
    }
    bool search(string &word, int &i){
        node* temp=root;
        for(auto c:word){
            if(temp->next.count(c-'a')==0){ i=-1; return false; }
            temp=temp->next[c-'a'];
            // i=max(i,temp->last);
            i=temp->last;
        }
        return true;
    }
};
class WordFilter {
public:
    trie* t=new trie();
    WordFilter(vector<string>& words) {
        int i=0;
        for(int i=0; i<words.size(); i++){
            string w=words[i];
            for(int j=0; j<w.length(); j++){
                string r=w.substr(j)+'{'+w;
                t->insert(r,i);
            }
        }        
    }
    
    int f(string pref, string suff) {
        int ans=-1;
        string s=suff+'{'+pref;
        t->search(s,ans);
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */