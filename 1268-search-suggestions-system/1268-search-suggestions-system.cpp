class node{
public:
    node *next[26];
    // priority_queue<string,vector<string>,greater<string>> pq;
    // priority_queue<string> pq;
    bool end;
    node(){
        memset(next,0,sizeof(next));
        end=false;
    }
};
class trie{
public:
    node *root=new node();
    map<node*,vector<string>> pq;
    void insert(string &s){
        node *temp=root;
        for(int i=0; i<s.length(); i++){
            if(!temp->next[s[i]-'a']){
                temp->next[s[i]-'a']=new node();
            }
            if(pq[temp->next[s[i]-'a']].size()<3){
                pq[temp->next[s[i]-'a']].push_back(s);
            }
            temp=temp->next[s[i]-'a'];
        }
        temp->end=true;
    }
    vector<vector<string>> search(string &s){
        vector<vector<string>> ans((int)s.length());
        node *temp=root;
        for(int i=0; i<s.length(); i++){
            if(temp->next[s[i]-'a']){
                ans[i]=pq[temp->next[s[i]-'a']];
                temp=temp->next[s[i]-'a'];
            }
            else{ break; }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie *t=new trie();
        sort(begin(products),end(products));
        for(auto &p:products){
            t->insert(p);
        }
        return t->search(searchWord);
    }
};