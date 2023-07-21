class node{
public:
    int sz;
    node *next[26];
    node(){
        sz=0; memset(next,0,sizeof(next));
    }
};
class Trie{
public:
    node *root;
    unordered_map<string, int> map;
    Trie(){
        root=new node();
    }
    void insert(string &word, int val){
        int diff=val-map[word];
        node *d=root;
        for(int i=0; i<word.length(); i++){
            if(!d->next[word[i]-'a']){
                d->next[word[i]-'a']=new node();
            }
            d=d->next[word[i]-'a'];
            d->sz+=diff;
        }
        map[word]=val;
    }
    int find(string &word){
        node *d=root;
        for(int i=0; i<word.length(); i++){
            // cout<<word[i]<<','<<d->sz<<' ';
            if(!d->next[word[i]-'a']){ return 0; }
            d=d->next[word[i]-'a'];
        }
        return d->sz;
    }
};
class MapSum {
public:
    Trie *T;
    MapSum() { T=new Trie(); }
    
    void insert(string key, int val) {
        T->insert(key,val);
    }
    
    int sum(string prefix) {
        return T->find(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */