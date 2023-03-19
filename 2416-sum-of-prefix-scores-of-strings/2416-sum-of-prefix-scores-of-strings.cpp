struct node{
    node* next[26]={};
    int cnt=0;
};
class Solution {
    node root;
public:
    void insert(string &word){
        auto r=&root;
        for(auto c:word){
            if(!r->next[c-'a']){
                r->next[c-'a']=new node();
            }
            (r->next[c-'a']->cnt)+=1;
            r=r->next[c-'a'];
        }
    }
    int search(string &word){
        auto r=&root;
        int ans=0;
        for(auto c:word){
            ans+=(r->next[c-'a']->cnt);
            r=r->next[c-'a'];
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto w:words){ insert(w); }
        vector<int> ans(words.size());
        for(int i=0; i<words.size(); i++){
            ans[i]=search(words[i]);
        }
        return ans;
    }
};