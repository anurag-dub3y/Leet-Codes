class node{
public:
    node* next[10];
    node(){ memset(next,0,sizeof(next));  }
};
class trie{
public:
    node* root=new node();
    void remove_first(int &num) {
        num %= static_cast<int>(pow(10, static_cast<size_t>(log10(num))));
    }
    void insert(string &n){
        node *r=root;
        // cout<<n<<' ';
        while(n.length()){
            int f=n.back()-'0';
            if(!r->next[f]){
                r->next[f]=new node();
            }
            r=r->next[f];
            n.pop_back();
        }
    }
    void search(node *r, int prev, vector<int>& ans){
        prev*=10;
        for(int i=0; i<10; i++){
            if(r->next[i]){
                ans.push_back(prev+i);
                search(r->next[i],prev+i,ans);
            }
        }
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        trie *t=new trie();
        for(int i=1; i<=n; i++){ 
            string s=to_string(i);
            reverse(s.begin(),s.end());
            t->insert(s); 
        }
        vector<int> ans;
        node *temp=t->root;
        t->search(temp,0,ans);
        return ans;
    }
};