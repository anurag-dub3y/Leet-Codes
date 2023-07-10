class Node{
public:
    Node *next[2];
    int size;
    Node(){
        size=0;
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
        for(int i=16; i>=0; i--){
            bool x = (n) & (1 << i); 
            if(!temp->next[x]){
                temp->next[x]=new Node();
            }
            temp->next[x]->size+=1; 
            temp=temp->next[x];
        }
    }
    int find(int x, int limit){
        int cnt=0;
        Node *temp=root;
        for(int i=16; i>=0 and temp; i--){
            bool limitBit=(limit&(1<<i)), xBit=(x&(1<<i));
            if(limitBit==0){ temp=temp->next[xBit]; continue; }
            if(temp->next[xBit]){ cnt+=temp->next[xBit]->size; }
            temp=temp->next[!xBit];
        }
        return cnt;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        sort(begin(nums),end(nums));
        Trie *T=new Trie();
        int ans=0;
        for(auto it:nums){ 
            ans+=T->find(it,high+1)-T->find(it,low);
            T->insert(it); 
        }
        return ans;   
    }
};

// Bit Limit_bit  Action
// 0      0       Cannot go to 1 subtree because 0^1=1 (bit ^ 1 subtree ) w/c is > limit_bit. 
//                So we move to 0 subtree to find possible pairs with n.
// 0      1       Count all in 0 subtree because 0^0=0 is strictly less than limit_bit (So all numbers in 0 subtree // will be in limit). 
//                Also, move to 1 subtree (0^1=1 <=limit_bit) to find possible pairs in that subtree.
// 1      0       Cannot go to 0 subtree (1^0=1 >limit_bit). Move to 1 subtree (1^1=0 <=limit_bit) to find possible // pairs.
// 1      1       Count all in 1 subtree (1^1=0 is strictly less than limit_bit). Move to 0 subtree to find possible // pairs.



