class node{
    public:
        node *next[26];
        int cnt=0;
        node(){
            memset(next,0,sizeof(next));
            cnt=1;
        }
};
class Solution {
public:
    node *root=new node();
    void insert(string &word){
        node *r=root;
        for(auto c:word){
            if(!r->next[c-'a']){
                r->next[c-'a']=new node();
            }
            else{
                (r->next[c-'a']->cnt)+=1;
            }
            r=r->next[c-'a'];
        }
    }
    int search(string &word){
        node *r=root;
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