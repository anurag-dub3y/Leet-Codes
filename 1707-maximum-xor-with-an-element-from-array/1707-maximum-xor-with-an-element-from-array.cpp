class Node{
public:
    Node *next[2];
    Node(){
        memset(next,0,sizeof(next));
    }
};
class Trie{
public:
    Node *root;
    Trie(){ 
        root=new Node(); 
    }
    void insert(int n){
        Node *temp=root;
        for(int i=31; i>=0; i--){
            int x=(n>>i)&1;
            if(!temp->next[x]){
                temp->next[x]=new Node();
            }
            temp=temp->next[x];
        }
    }
    int dfs(int n){
        int maxNum=0;
        Node *temp=root;
        for(int i=31; i>=0; i--){
            int x=(n>>i)&1;
            if(temp->next[1-x]){
                maxNum|=(1<<i);
                temp=temp->next[1-x];
            }
            else{ temp=temp->next[x]; }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        vector<pair<pair<int,int>,int>> vp;
        for(int i=0; i<q.size(); i++){
            vp.push_back({{q[i][0],q[i][1]},i});
        }
        sort(begin(vp),end(vp),[&](const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
            return a.first.second<b.first.second; 
        });
        sort(begin(nums),end(nums));
        vector<int> ans(q.size(),-1);
        Trie T;
        int i=0;
        for(int j=0; j<vp.size(); j++){
            while(i<nums.size() and nums[i]<=vp[j].first.second){
                T.insert(nums[i++]);
            }
            if(i==0){ continue; }
            ans[vp[j].second]=T.dfs(vp[j].first.first);
        }
        return ans;
    }
};



