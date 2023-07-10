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
    
    void insert(string &word) {
        node *p=root;
        for(int i=0; i<word.length(); i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a']=new node();
            }
            p=p->next[word[i]-'a'];
        }
        p->is_end=true;
    }
    
    bool search(deque<char> &dq) {
        node* dummy=root;
        for(auto it=dq.rbegin(); it!=dq.rend(); it++){
            if(!dummy or !dummy->next[*it-'a']){ return false; }
            dummy=dummy->next[*it-'a'];
            if(dummy and dummy->is_end){ return true; }
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie *t=new Trie();
    string s="";
    deque<char> dq;
    int mx=0;
    StreamChecker(vector<string>& words) {
        for(auto &w:words){
            mx=max(mx,(int)w.length());
            reverse(w.begin(),w.end());
            t->insert(w);
            // cout<<w<<' ';
        }
    }
    
    bool query(char letter) {
        dq.push_back(letter);
        if(dq.size()>mx){ dq.pop_front(); }
        // node *head=t->root;
        return t->search(dq);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */